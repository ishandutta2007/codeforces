import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
	val n = nextInt()
	val pos = IntArray(200011) { 0 }
	var left = 0
	var right = 1

	repeat(n) {
		val op = next()[0]
		val id = nextInt() - 1
		if (op == 'L') {
			pos[id] = left
			left--
		} else if (op == 'R') {
			pos[id] = right
			right++
		} else {
			val ans = minOf(
				pos[id] - left - 1,
				right - pos[id] - 1)
			sb.appendLine(ans)
		}
	}
    print(sb)
}