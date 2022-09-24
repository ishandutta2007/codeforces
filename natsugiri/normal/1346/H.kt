import java.util.*

class Seg(val c: Int, val l: Int, val r: Int, val i: Int): Comparable<Seg> {
	override fun compareTo(other: Seg): Int {
		if (c != other.c) return c - other.c
		return r - other.r
	}
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val even = mutableListOf<Seg>()
	val odd = mutableListOf<Seg>()

	repeat(n) {
		val l = nextInt() - 1
		val r = nextInt()
		if ((r-l) % 2 == 0) {
			even.add(Seg((r+l) / 2, l, r, it))
		} else {
			odd.add(Seg((r+l) / 2, l, r, it))
		}
	}
	repeat(m) {
		val l = nextInt() - 1
		val r = nextInt()
		if ((r-l) % 2 == 0) {
			even.add(Seg((r+l) / 2, l, r, -1))
		} else {
			odd.add(Seg((r+l) / 2, l, r, -1))
		}
	}

	val ans = IntArray(n) { -1 }

	fun calc(segs: MutableList<Seg>) {
		segs.sort()
		var i0 = 0
		var i1 = 0
		var i2 = 1
		var i3 = 1
		while (i1 < segs.size) {
			while (i2 < segs.size && segs[i1].c == segs[i2].c) i2++

			i3 = maxOf(i3, i2)
			while (i3 < segs.size && segs[i1].c + 1 == segs[i3].c) i3++

			while (segs[i0].c +	1 < segs[i1].c) i0++

			var p1 = i1-1
			var p2 = i2-1
			var p3 = i3-1
			for (k in i2-1 downTo i1) {
				if (segs[k].i == -1) continue

				while (p1 >= i0 && (segs[p1].i != -1 || segs[p1].l < segs[k].l)) p1--
				while (p2 >= i1 && (segs[p2].i != -1 || segs[p2].l < segs[k].l)) p2--
				while (p3 >= i2 && (segs[p3].i != -1 || segs[k].r < segs[p3].r)) p3--

				var a = -1
				if (p1 >= i0) a = segs[p1].r - segs[p1].l

				var b = -1
				if (p2 >= i1) b = segs[p2].r - segs[p2].l

				var c = -1
				if (p3 >= i2) c = segs[p3].r - segs[p3].l


				if (a == -1 && b == -1) ans[segs[k].i] = -1
				else if (b == -1 && c == -1) ans[segs[k].i] = -1
				else {
					var d = maxOf(a, b)
					var e = maxOf(b, c)
					ans[segs[k].i] = (segs[k].r - segs[k].l - minOf(d, e)) / 2
				}
			}

			i1 = i2
			i2++
		}
	}

	calc(even)
	calc(odd)
	println(ans.joinToString(" "))
}