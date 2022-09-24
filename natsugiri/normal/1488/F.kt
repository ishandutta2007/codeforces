import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val c = IntArray(n) { nextInt() }
	val q = nextInt()

	val b = Array(n) { mutableListOf<Pair<Int, Int> >() }

	repeat(q) { i ->
		val l = nextInt() - 1
		val r = nextInt() - 1

		b[r].add(Pair(l, i))
	}

	val ans = LongArray(q) { 0L }

	val sz = mutableListOf(0L)
	val value = mutableListOf(Long.MAX_VALUE)
	val szSums = mutableListOf(0L)
	val sums = mutableListOf(0L)

	repeat(n) { r ->
		var nextSz = 1L
		while (value.last() <= c[r]) {
			nextSz += sz.last()
			sz.removeLast()
			value.removeLast()
			szSums.removeLast()
			sums.removeLast()
		}

		sums.add(sums.last() + nextSz * c[r])
		szSums.add(szSums.last() + nextSz)
		value.add(c[r].toLong())
		sz.add(nextSz)

		b[r].forEach { (l, i) ->
			val len = r - l + 1
			var lo = -1
			var hi = szSums.size - 1
			while (hi - lo > 1) {
				val mid = (hi + lo) / 2
				if (szSums.last() - szSums[mid] <= len) hi = mid
				else lo = mid
			}

			val rest = len.toLong() - (szSums.last() - szSums[hi])
			val tmp = sums.last() - sums[hi] + value[hi] * rest

			ans[i] = tmp
		}
	}

	println(ans.joinToString(" "))

}