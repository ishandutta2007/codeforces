import java.util.*
import kotlin.math.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val k = nextInt()
	val x = nextInt()
	val a = LongArray(n) { nextLong() }

	val pq = PriorityQueue<Long>()

	fun ok(mid: Long): Boolean {
		var sum = 0L
		var rem = 0
		pq.clear()
		for (i in 0 .. n-1) {
			pq.add(-a[i])
			sum += a[i]
			while (sum > mid) {
				sum += pq.poll()
				rem++
			}
			if (rem > k) return false
			if (pq.size == x) {
				sum = 0
				pq.clear()
			}
		}
		pq.clear()
		return true
	}

	var lo = -1L
	var hi = 1L
	while (!ok(hi)) {
		lo = hi
		hi += hi
	}

	while (hi - lo > 1) {
		val mid = (lo + hi) / 2
		if (ok(mid)) {
			hi = mid
		} else {
			lo = mid
		}
	}
	println(hi)
}