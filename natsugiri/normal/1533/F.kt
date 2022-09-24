import java.util.*

fun IntArray.lowerBound(key: Int): Int {
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
	val s = next()
    val n = s.length
	val sums0 = IntArray(n+1) { 0 }
	val sums1 = IntArray(n+1) { 0 }
	for ( i in 0 .. n-1) {
		sums0[i+1] = sums0[i]
		sums1[i+1] = sums1[i]
		if (s[i] == '0') sums0[i+1]++
		else sums1[i+1]++
	}


	for (k in 1 .. n) {
		var ans = 0
		var i = 0
		while (i < n) {
			val a = sums0.lowerBound(sums0[i] + k + 1) - 1
			val b = sums1.lowerBound(sums1[i] + k + 1) - 1
			ans++
			i = maxOf(a, b)
		}

		if (k > 1) sb.append(' ')
		sb.append(ans)
	}
	println(sb)
}