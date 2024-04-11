import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
	repeat(n) {
		val s = next()

		var l = 0
		var g = 0
		var e = 0
		s.forEach { x ->
			if (x == '<') l++
			if (x == '>') g++
			if (x == '=') e++
		}

		if (e == s.length) {
			sb.appendLine('=')
		} else if (l == 0) {
			sb.appendLine('>')
		} else if (g == 0) {
			sb.appendLine('<')
		} else {
			sb.appendLine('?')
		}
	}
	print(sb)
}