import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val q = nextInt()
	val c = Array(n) { next().toCharArray() }

	val ord = Array(m+1) { IntArray(n) { it } }

	val b = Array(26) { mutableListOf<Int>() }

	val sb = StringBuilder()

	for (j in m-1 downTo 0) {
		for (x in 0 .. 25) b[x].clear()

		for (i in 0 .. n-1) {
			val k = ord[j+1][i]
			b[c[k][j] - 'a'].add(k)
		}

		var pos = 0
		for (x in 0 .. 25) {
			b[x].forEach { k ->
				ord[j][pos] = k
				pos++
			}
		}
	}

	repeat (q) {
		val s = next()

		var ans = 0

		var left = 0
		var up = 0
		var down = n
		var j = 0
		while (j < m) {
			var lb = 0
			if (true) {
				var lo = up-1
				var hi = down
				while (hi - lo > 1) {
					val mid = (hi + lo) / 2
					val tmp = c[ord[left][mid]][j]
					if (tmp < s[j]) lo = mid
					else hi = mid
				}
				lb = hi
			}

			var ub = 0
			if (true) {
				var lo = up-1
				var hi = down
				while (hi - lo > 1) {
					val mid = (hi + lo) / 2
					val tmp = c[ord[left][mid]][j]
					if (tmp <= s[j]) lo = mid
					else hi = mid
				}
				ub = hi
			}

			if (lb == ub) {
				if (left == j) {
					ans = -1
					break
				} else {
					ans++
					left = j
					up = 0
					down = n
				}
			} else {
				j++
				up = lb
				down = ub
			}
		}

		sb.appendLine(ans)
	}

	println(sb)
}