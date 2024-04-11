import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val k = nextLong()
	val a = LongArray(n) { nextLong() }

	var lo = 0
	var hi = n + 1
	while (hi - lo > 1) {
		val mid = (lo + hi) / 2

		var cnt = 0L
		var rest = 0L
		for (i in n-mid .. n-1) {
			if (rest >= a[i]) {
				rest -= a[i]
			} else {
				rest = k - a[i]
				cnt++
			}
		}

		if (cnt <= m) {
			lo = mid
		} else {
			hi = mid
		}
	}

	println(lo)
}