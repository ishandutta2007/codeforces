import java.util.*

fun LongArray.lowerBound(key: Long): Int {
    var lo = -1
    var hi = this.size
    while (hi - lo > 1) {
        val mid = (lo + hi) / 2
        if (this[mid] < key) lo = mid
        else hi = mid
    }
    return hi
}


fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
	val a = LongArray(n) { nextLong() }
	val b = LongArray(n+1) { nextLong() }
	a.sort()
	b.sort()

	val pre = LongArray(n+1) { 0 }
	val suf = LongArray(n+1) { 0 }

	pre[0] = -10000000000000L
	suf[0] = -10000000000000L
	for (i in 0 .. n-1) {
		pre[i+1] = maxOf(pre[i], b[i] - a[i])
		suf[i+1] = maxOf(suf[i], b[n-i] - a[n-1-i])
	}

	val m = nextInt()
	repeat (m) {
		val c = nextLong()

		val k = a.lowerBound(c)
		val ans = maxOf(pre[k], maxOf(suf[n-k], b[k] - c))

		if (it > 0) sb.append(' ')
		sb.append(ans)
	}
	println(sb)
}