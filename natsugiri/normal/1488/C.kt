import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
	val sb = StringBuilder()
	repeat(t) {
		val n = nextInt()
		val x_ = nextInt() - 1
		val y_ = nextInt() - 1
		var x = minOf(x_, y_)
		var y = maxOf(x_, y_)

		var lo = -1
		var hi = n + 1
		while (hi - lo > 1) {
			val mid = (hi + lo) / 2

			var ok = true
			if (mid < x) ok = false
			if (mid < n-1-y) ok = false
			val q = maxOf(x, mid - x, (mid + x) / 2)
			val w = maxOf((n-1-y), mid - (n-1-y), (mid + (n-1-y)) / 2)
			if (q + w + 2 < n) ok = false

			if (ok) {
				hi = mid
			} else {
				lo = mid
			}
		}


		sb.appendLine(hi)
	}
	print(sb)
}