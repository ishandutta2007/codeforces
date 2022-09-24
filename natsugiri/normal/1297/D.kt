import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {
        val n = nextInt()
        var k = nextInt()
        val p = Array<Pair<Int, Int> >(n) {
            val a = nextInt()
            Pair<Int, Int>(a, it)
        }
        p.sortBy({ it.first })
        var d = LongArray(n) {0}

        repeat(n - 1) {
            val diff = p[it + 1].first - p[it].first
            val area = (diff - 1).toLong() * (it + 1)
            if (area <= k) {
                d[it] = d[it] + diff - 1
                k -= area.toInt()
            } else {
                d[it] = d[it] + k / (it + 1)
                d[it]++
                d[it - k % (it + 1)]--
                k = 0
            }
        }

        if (k > 0) {
            d[n - 1] = d[n-1] + k / n + 1
			d[n - 1 - k % n]--
		}


		for (i in n-2 downTo 0) {
			d[i] += d[i+1]
		}

		val ans = LongArray(n)
		repeat(n) {
			ans[p[it].second] = d[it]
		}
		println(ans.joinToString(" "))
    }
}