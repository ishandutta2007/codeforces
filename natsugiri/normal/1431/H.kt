import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val k = nextLong()
	val a = LongArray(n) { nextLong() }
	val b = LongArray(m) { nextLong() }

	val target = maxOf(a[n-1], b[m-1])

	val c = Array(n) { LongArray(m) { nextLong() } }
	val x = mutableListOf<Pair<Long, Long> > ()

	if (true) {
		x.add(Pair(0L, c[0][0]))

		var i = 1
		var j = 1
		while (i < n || j < m) {
			val p: Pair<Long, Long>
			if (i == n || (j < m && b[j] < a[i])) {
				var tmp = 0L
				for (h in 0 .. i-1) tmp = maxOf(tmp, c[h][j])
				p = Pair(b[j], tmp)
				j++
			} else {
				var tmp = 0L
				for (h in 0 .. j-1) tmp = maxOf(tmp, c[i][h])
				p = Pair(a[i], tmp)
				i++
			}

			while (!x.isEmpty()
				&& x[x.size-1].first == p.first
				&& x[x.size-1].second < p.second) {
				x.removeAt(x.size-1)
			}

			if (x.isEmpty() || x[x.size-1].second < p.second) {
				x.add(p)
			}
		}
	}

	var ans = Long.MAX_VALUE

	for (s in 0 .. x.size - 1) {
		var cnt = 0L
		var total = 0L
		var power = 0L

		for (i in 0 .. x.size - 1) {
			val nxt: Long
			if (i == x.size - 1) {
				nxt = target
			} else {
				nxt = x[i+1].first
			}

			power = maxOf(power, x[i].second)
			if (i == s) {
				power = maxOf(power, x[i].second + k)
			}

			if (nxt > total) {
				val g = (nxt - total + power - 1) / power
				total += power * g
				cnt += g
			}
		}
		ans = minOf(ans, cnt)
	}

	println(ans)
}