import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = IntArray(n) { nextInt() }
		val ma = a.max()!!
		val cnt = a.count({it -> it == ma})

		var ans = 0
		if (cnt == 1) {
			ans = a.indexOf(ma)
		} else {
			ans = a.indexOf(a.min()!!)
		}

		sb.appendLine(ans+1)
	}
	print(sb)
}