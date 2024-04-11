import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val sb = StringBuilder()
	repeat(n) {
		val a = nextLong()
		val b = nextLong()
		val k = nextLong()
		var ans = (a-b) * (k/2)
		if (k % 2 == 1L) {
			ans += a
		}
		sb.appendLine(ans)
	}
	print(sb)
}