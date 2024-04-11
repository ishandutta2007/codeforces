import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val k = IntArray(n) { 0 }
	val t = IntArray(n) { 0 }
	repeat(n) { i ->
		k[i] = nextInt()
		t[i] = nextInt()
	}

	val ans = IntArray(n) { -2 }
	var sum = 0
	val idx = mutableListOf<Int>()

	repeat(n) { i ->
		if (t[i] == 1) {
			ans[i] = sum + 1
			sum += k[i]
		} else {
			idx.add(i)
		}
	}

	var yes = true
	val rest = m - sum
	if (rest < 0) {
		yes = false
	}
	if (yes) {
		val limit = rest / 2
		val dp = Array(idx.size+1) { BooleanArray(limit+1) { false } }

		var total = 0
		dp[0][0] = true

		repeat(idx.size) { i ->
			total += k[idx[i]]

			for (j in 0 .. limit) {
				if (dp[i][j]) {
					dp[i+1][j] = true
					if (j + k[idx[i]] <= limit) {
						dp[i+1][j + k[idx[i]]] = true
					}
				}
			}
		}

		var limit2 = rest - limit

		yes = false

		for (j in 0 .. limit) {
			if (dp[idx.size][j] && total - j <= limit2) {
				yes = true
				val v1 = mutableListOf<Int>()
				val v2 = mutableListOf<Int>()
				var pos = j
				for (i in idx.size-1 downTo 0) {
					if (dp[i][pos]) {
						v2.add(idx[i])
					} else {
						v1.add(idx[i])
						pos -= k[idx[i]]
					}
				}

				var start1 = sum + 1
				v1.forEach { id ->
					ans[id] = start1 + 1
					start1 += k[id] * 2
				}
				var start2 = sum
				v2.forEach { id ->
					ans[id] = start2 + 1
					start2 += k[id] * 2
				}

				break
			}
		}
	}

	if (yes) {
		println(ans.joinToString(" "))
	} else {
		println("-1")
	}
}