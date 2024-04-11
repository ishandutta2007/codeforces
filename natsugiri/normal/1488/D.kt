import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
	val sb = StringBuilder()
	repeat(t) {
		val n = nextLong()
		val s = nextLong()

		var lo = 1L
		var hi = s + 1L
		while (hi - lo > 1L) {
			val mid = (lo + hi) / 2

			var sum = 0L
			var cur = mid
			for (i in 0L .. n-1L) {
				if (cur == 1L) {
					sum += n - i
					break
				}
				sum += cur
				cur = (cur + 1) / 2
				if (sum > s) {
					break
				}
			}

			if (sum <= s) {
				lo = mid
			} else {
				hi = mid
			}
		}

		sb.appendLine(lo)
	}
	print(sb)
}