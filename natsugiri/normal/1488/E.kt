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

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
	val sb = StringBuilder()
	repeat(t) {
		val n = nextInt()
		val a = IntArray(n) { nextInt() }

		val last = IntArray(n+1) { -1 }
		val left = IntArray(n) { -1 }

		for (i in 0..n-1) {
			if (last[a[i]] == -1) {
				last[a[i]] = i
			} else {
				// last[a[i]], i;
				left[i] = last[a[i]]
				last[a[i]] = -2
			}
		}

		for (i in 0..n) {
			if (last[i] >= 0) {
				// last[i], last[i]
				left[last[i]] = last[i]
			}
		}

		val rmq = Rmq(n) { 0L }

		var ans = 0L
		for (i in 0..n-1) {
			if (left[i] != -1) {
				var add = 2
				if (left[i] == i) add = 1

				var tmp = add - rmq.min(left[i], i+1)
				if (tmp == 2L && left[i] + 1 < i) {
					tmp = 3L
				}
				ans = maxOf(ans, tmp)
				rmq.modify(left[i], -tmp)
			}
		}

		sb.appendLine(ans)
	}
	print(sb)
}