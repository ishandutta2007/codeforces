import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val tc = nextInt()
	val sb = StringBuilder()
	repeat(tc) {
		val n = nextInt()
		val k = nextInt()

		var ans = 0
		repeat (n) {
			val l = nextInt()
			val r = nextInt()

			if (l <= k && k <= r) {
				val tmp = r - maxOf(k, l) + 1
				ans = maxOf(ans, tmp)
			}
		}
		sb.appendLine(ans)
	}
	print(sb)
}