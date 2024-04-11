import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val q = nextInt()

	val C = LongArray(m) { 0L }
	val R = LongArray(n) { 0L }

	val A = Array(n) {
		IntArray(m) { 0 }
	}

	for (i in 0..n-1) for (j in 0..m-1) {
		val a = nextLong()
		R[i] += a
		C[j] += a
		A[i][j] = a.toInt()
	}

	fun calcV(V: LongArray): Long {
		val sum = V.sum()
		if (sum == 0L) {
			return 0L
		}
		var center = 0
		var left = 0L
		for (i in 0 .. V.size-1) {
			left += V[i]
			if (left * 2L >= sum) {
				center = i
				break
			}
		}

		var ret = 0L
		for (i in 0 .. V.size-1) {
			if (i <= center) {
				ret += V[i] * (center - i)
			} else {
				ret += V[i] * (i - center)
			}
		}

		return ret
	}

	fun calc(): Long {
		return calcV(R) + calcV(C)
	}

	val ans = LongArray(q + 1)
	ans[0] = calc()

	for (i in 1 .. q) {
		val r = nextInt() - 1
		val c = nextInt() - 1
		val w = nextLong()
		R[r] = R[r] - A[r][c] + w
		C[c] = C[c] - A[r][c] + w

		A[r][c] = w.toInt()

		ans[i] = calc()
	}

	println(ans.joinToString(" "))
}