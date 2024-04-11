import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
    val a = IntArray(n) { nextInt() }
	val b = Array<MutableList<Int>>(1001) { mutableListOf<Int>() }
	repeat(n) { i ->
		b[a[i]].add(i)
	}

	var ans = 0L
	var x = 0L
	val arr = mutableListOf<Int>()

	for (t in 1000 downTo 0) {
		b[t].forEach { k ->
			arr.add(k+1)
			ans += a[k] * x + 1
			x += 1
		}
	}


	sb.appendLine(ans)
	sb.appendLine(arr.joinToString(" "))
	print(sb)
}