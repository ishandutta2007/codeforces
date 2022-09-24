import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val a = IntArray(n) { nextInt() }
	val c = IntArray(1011) { 0 }
	val ans = mutableListOf<Int>()
	for (i in n-1 downTo 0) {
		if (c[a[i]] == 0) {
			ans.add(a[i])
		}
		c[a[i]] = 1
	}
	ans.reverse()
	println(ans.size)
    println(ans.joinToString(" "))
}