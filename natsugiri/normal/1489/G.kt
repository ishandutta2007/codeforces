import java.util.*

class UnionFind(n: Int) {
    val a = IntArray(n) { -1 }

    fun root(i: Int): Int {
        if (a[i] < 0) return i
        a[i] = root(a[i])
        return a[i]
    }

    fun link(i: Int, j: Int) {
        val i0 = root(i)
        val j0 = root(j)
        if (a[i0] <= a[j0]) {
            a[i0] += a[j0]
            a[j0] = i0
        } else {
            a[j0] += a[i0]
            a[i0] = j0
        }
    }

    fun same(i: Int, j: Int): Boolean {
        return root(i) == root(j)
    }

    fun count_node(i: Int): Int {
        return -a[root(i)]
    }
}

class Edge(val x: Int, val y: Int, val w: Long) {
}

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val a = LongArray(n) { nextLong() }

	val e = Array(m) {
		val x = nextInt()-1
		val y = nextInt()-1
		val w = nextLong()
		Edge(x, y, w)
	}

	e.sortBy { it.w }

	val u = UnionFind(n)
	val pq = PriorityQueue<Pair<Long, Int> >(n) { x, y ->
		var ret = 0
		if (x.first < y.first) ret = -1
		else if (x.first > y.first) ret = 1
		return@PriorityQueue ret
	}

	repeat(n) { i ->
		pq.add(Pair(a[i], i))
	}

	var ans = 0L
	var j = 0
	repeat(n-1) {
		val a = pq.poll()
		var b = pq.poll()

		while (u.same(a.second, b.second)) {
			b = pq.poll()
		}

		pq.add(a)
		pq.add(b)

		while (j < e.size && u.same(e[j].x, e[j].y)) {
			j++
		}

		if (j < e.size && e[j].w < a.first + b.first) {
			ans += e[j].w
			u.link(e[j].x, e[j].y)
		} else {
			ans += a.first + b.first
			u.link(a.second, b.second)
		}
	}

	println(ans)
}