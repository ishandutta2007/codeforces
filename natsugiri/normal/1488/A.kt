import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val sb = StringBuilder()
	repeat(n) {
		val x = nextLong()
		var y = nextLong()
		var ans = 0L
		var s = x * 1000000000L
		while (s >= x) {
			val q = y / s
			ans += q
			y -= q * s
			s /= 10
		}
		ans += y
		sb.appendLine(ans)
	}
	print(sb)
}