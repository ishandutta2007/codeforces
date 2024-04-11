import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
	val sb = StringBuilder()
	repeat(t) {
		val n = nextInt()
		var k = nextInt()
		val s = next()

		var dep = 0
		var prefix = 0
		repeat(n) { i ->
			if (s[i] == '(') {
				dep++
			} else {
				dep--
				if (dep == 0) {
					prefix++
				}
			}
		}

		val add = minOf(k, n/2 - prefix)
		val ans = prefix + add

		sb.appendLine(ans)
	}
	print(sb)
}