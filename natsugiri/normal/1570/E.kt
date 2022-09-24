import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val t = nextInt()
	repeat(t) {
		val s = next()
		var ans = 0
		var zero = -1
		s.forEach { c ->
			if (c == '0') {
				if (zero >= 0) zero++
			} else {
				if (zero >= 0) ans += zero
				zero = 0
			}
		}
		sb.appendLine(ans)
	}
	print(sb)
}