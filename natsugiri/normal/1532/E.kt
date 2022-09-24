import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val a = IntArray(n) { nextInt() }
	var sum = 0L
	val c = IntArray(1000011) { 0 }
	val ans = mutableListOf<Int>()

	a.forEach {
	    sum += it.toLong()
		c[it]++
	}

	repeat(n) { i ->
		sum -= a[i]
		c[a[i]]--
		if (sum % 2 == 0L && sum / 2 <= 1000000 && c[sum.toInt() / 2] > 0) {
			ans.add(i+1)
		}
		c[a[i]]++
		sum += a[i]
	}
	println(ans.size)
	if (ans.size >= 1) {
		println(ans.joinToString(" "))
	}
}