import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val tc = nextInt()
	repeat(tc) {
		val n = nextInt()

		var atmost = 300000
		var atleast = 0

		repeat(n) {
			val s = next()
			val t = next()
			val f = nextInt()

			val len = minOf(s.length, t.length)

			var tmp = len
			for (i in 0 .. len-1) {
				if (s[s.length-1-i] != t[t.length-1-i]) {
					tmp = i
					break
				}
			}

			if (f == 1) {
				atmost = minOf(atmost, tmp)
			} else {
				atleast = maxOf(atleast, tmp+1)
			}
		}

		if (atleast <= atmost) {
			sb.appendLine(atmost - atleast + 1)
			for (i in 0 .. atmost - atleast) {
				if (i > 0) {
					sb.append(' ')
				}
				sb.append(i + atleast)
			}
			sb.append('\n')
		} else {
			sb.appendLine(0)
		}
	}
	print(sb)
}