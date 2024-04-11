import java.util.*

class Rmq(val n: Int) {
    val a = LongArray(n*2) { Long.MAX_VALUE }

    constructor(n: Int, init: (Int) -> Long) : this(n) {
        for (i in 0..n - 1) a[i + n] = init(i)
        for (i in n - 1 downTo 1) a[i] = minOf(a[i*2], a[i*2 + 1])
    }

    fun at(i: Int): Long {
        return a[i + n]
    }

    fun modify(i_: Int, v: Long) {
        var i = i_ + n
        a[i] = v
        while (i > 1) {
            i /= 2
            a[i] = minOf(a[i*2], a[i*2 + 1])
        }
    }

    fun min(l_: Int, r_: Int): Long {
        var l = l_ + n
        var r = r_ + n
        var ret = Long.MAX_VALUE
        while (l < r) {
            if ((l and 1) == 1) { ret = minOf(ret, a[l]); l++; }
            if ((r and 1) == 1) { r--; ret = minOf(ret, a[r]); }
            l /= 2
            r /= 2
        }
        return ret
    }
}

class Pair(val i: Int, val j: Int) {
}

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()
	val a = Array(n) { mutableListOf<Int>() }
	val b = Array(n) { mutableListOf<Int>() }
	val ps = mutableListOf<Pair>()

	repeat(n) { i ->
		val k = nextInt()
		repeat(k) {
			a[i].add(nextInt())
		}
		repeat(k) {
			b[i].add(nextInt())
		}

		repeat(k) { j ->
			ps.add(Pair(i, j))
		}
	}

	ps.sortWith(compareBy(
		{ it.i + b[it.i][it.j] },
		{ -it.i }
		))

	val rmq = Rmq(m+1) { Long.MAX_VALUE }
	rmq.modify(m, 0)

	ps.forEach {
		val i = it.i
		val j = it.j
		val lo = b[i][j]
		val hi = minOf(lo + i, m) + 1
		if (lo < hi) {
			val nxt = rmq.min(lo, hi) - a[i][j].toLong()
			val tmp = rmq.at(lo)
			if (nxt < tmp) {
				rmq.modify(lo, nxt)
			}
		}
	}

	val ans = -rmq.min(0, m+1)
	println(ans)
}