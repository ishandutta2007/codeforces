import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {
		val n = nextInt()
		val p = mutableListOf<Pair<Int, Int> >()
		repeat(n) {
			val a = nextInt()
			val b = nextInt() + 1
			p.add(Pair(a, 1))
			p.add(Pair(b, -1))
		}
		p.sortBy({ it.first })
		var i = 0
		var cnt = 0
		var ans = -1
		while (i < p.size) {
			var j = i
			var add = 0
			var sub = 0
			while (j < p.size && p[i].first == p[j].first) {
				if (p[j].second == 1) {
					add++
				} else {
					sub++
				}
				j++
			}

			if (cnt + add - sub == 1) {
				ans = p[i].first
				break
			}
			cnt += add
			cnt -= sub
			i = j
		}
		println(ans)
    }
}