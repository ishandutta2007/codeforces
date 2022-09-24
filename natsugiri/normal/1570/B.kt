import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val a1 = nextInt()
	val a2 = nextInt()
	val k1 = nextInt()
	val k2 = nextInt()
	val n = nextInt()

	var mi = 0
	var ma = 0

	val safe = a1 * (k1 - 1) + a2 * (k2 - 1)
	if (safe >= n) {
		mi = 0
	} else {
		mi = n - safe
	}

	val g1 = minOf(a1, n / k1)
	val h1 = minOf(a2, (n - k1 * g1) / k2)
	if (ma < g1 + h1) ma = g1 + h1

	val g2 = minOf(a2, n / k2)
	val h2 = minOf(a1, (n - k2 * g2) / k1)
	if (ma < g2 + h2) ma = g2 + h2

	print("%d %d\n".format(mi, ma))
}