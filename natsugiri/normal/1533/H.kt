import java.util.*

fun main() = with(Scanner(System.`in`)) {
    // val sb = StringBuilder()
	val n = nextInt()
	val m = nextInt()
	val s = Array(n) { next() }

	var C = LongArray(32) { 0L }

	for (mask in 1 .. 31) {
		var tmp = 0L
		val height = IntArray(m) { 0 }

		for (i in 0 .. n-1) {

			val stkX = mutableListOf<Int>()
			val stkH = mutableListOf<Int>()
			stkX.add(0)
			stkH.add(-1)
			var area = 0L

			for (j in 0 .. m-1) {
				val c = s[i][j] - 'A'
				assert(0 <= c && c < 5)
				if (mask.shr(c).and(1) == 0) {
					height[j] = 0
				} else {
					height[j]++
				}

				while (!stkH.isEmpty() && stkH.last() >= height[j]) {
					val h = stkH.last().toLong()
					val x = stkX.last()

					stkH.removeLast()
					stkX.removeLast()

					area -= h * (x - stkX.last())

				}

				area += height[j] * (j + 1L - stkX.last())

				stkX.add(j + 1)
				stkH.add(height[j])
				tmp += area
			}
		}

		C[mask] += tmp
	}

	// println(C.joinToString(" "))

	for (i in 0 .. 31) for (j in 0 .. 31) {
		if (i != j && (i and j) == i) {
			C[j] -= C[i]
		}
	}

	val ans = LongArray(5) { 0L }
	for (mask in 1 .. 31) {
		var cnt = 0
		for (t in 0 .. 4) if ((mask.shr(t) and 1) == 1) {
			cnt++
		}

		if (cnt > 0) {
			ans[cnt-1] += C[mask]
		}
	}
	// println(C.joinToString(" "))
	println(ans.joinToString(" "))
}