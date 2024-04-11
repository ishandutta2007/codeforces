import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {
        val n = nextInt()
		val m = nextInt()
		val a = IntArray(n)
		val b = IntArray(n)

        repeat(n) {
			a[it] = nextInt()
			b[it] = nextInt()
		}

		val idx = Array<Int>(n) { it }
		idx.sortBy { a[it] }

		val pq = PriorityQueue<Int>() { i, j ->
			return@PriorityQueue b[i] - b[j]
		}

		val ans = IntArray(n)
		var day = 0
		var i = 0
		while (i < n) {
			while (day < a[idx[i]] && pq.size > 0) {
				val len = minOf(m, pq.size)
				repeat(len) {
					val k = pq.poll()
					ans[k] = day
				}
				day++
			}
			day = a[idx[i]]
			var j = i
			while (j < n && a[idx[i]] == a[idx[j]]) {
				pq.add(idx[j])
				j++
			}
			val len = minOf(m, pq.size)
			repeat(len) {
				val k = pq.poll()
				ans[k] = day
			}
			day++

			i = j
		}

		while (pq.size > 0) {
			val len = minOf(m, pq.size)
			repeat(len) {
				val k = pq.poll()
				ans[k] = day
			}
			day++
		}

		var delay = 0
		repeat(n) {
			if (ans[it] > b[it]) delay = maxOf(delay, ans[it] - b[it])
		}
		println(delay)
		println(ans.joinToString(" "))
    }
}