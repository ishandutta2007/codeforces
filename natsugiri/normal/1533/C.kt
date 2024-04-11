import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val tc = nextInt()
	val sb = StringBuilder()
	repeat(tc) {
		val n = nextInt()
		val k = nextInt()
		val s = next().toCharArray()

		var one = 0
		s.forEach {
			if (it == '1') one++
		}

		var ans = 0
		var pos = 0
		while (one >= 1) {
			ans++
			if (s[pos] == '1') {
				one--
			}
			s[pos] = 'e'
			// sb.appendLine(s.joinToString(""))
			if (one >= 1) {
				var cnt = k
				while (cnt >= 1) {
					pos++
					if (pos >= n) pos -= n
					if (s[pos] != 'e') {
						cnt--
					}
				}
			}
		}
		sb.appendLine(ans)
	}
	print(sb)
}