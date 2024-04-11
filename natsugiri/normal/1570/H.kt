import java.util.*

val MOD = 998244353L

fun add(x: Long, y: Long): Long {
	val z = x + y
	return if (z >= MOD) z - MOD else z
}

fun sub(x: Long, y: Long): Long {
	val z = MOD + x - y
	return if (z >= MOD) z - MOD else z
}

fun mul(x: Long, y: Long): Long {
	return x * y % MOD
}

fun pow(x_: Long, y_: Long): Long {
	var x = x_
	var y = y_
	var r = 1L
	if (x >= MOD) x %= MOD

	while (y > 0) {
		if (y.and(1) == 1L) r = mul(r, x)
		x = mul(x, x)
		y /= 2
	}
	return r
}


var w = Array<String>(0) { "" }

class Data : Comparable<Data> {
	val i0: Int
	val j0: Int
	val i1: Int
	val j1: Int

	constructor(i0_: Int, j0_: Int, i1_: Int, j1_: Int) {
		val x0: Int
		val y0: Int
		if (i0_ == -1 || j0_ == 0 || w[i0_].length == j0_) {
			x0 = -1
			y0 = 0
		} else {
			x0 = i0_
			y0 = j0_
		}
		val x1: Int
		val y1: Int
		if (i1_ == -1 || j1_ == 0 || w[i1_].length == j1_) {
			x1 = -1
			y1 = 0
		} else {
			x1 = i1_
			y1 = j1_
		}

		if (x0 < x1 || (x0 == x1 && y0 < y1)) {
			i0 = x0
			j0 = y0
			i1 = x1
			j1 = y1
		} else {
			i0 = x1
			j0 = y1
			i1 = x0
			j1 = y0
		}
	}

	constructor(i0_: Int, j0_: Int, i1_: Int, j1_: Int, dummy: Boolean) {

		val x0: Int
		val y0: Int
		if (i0_ == -1 || j0_ == 0 || w[i0_].length == j0_) {
			x0 = -1
			y0 = 0
		} else {
			x0 = i0_
			y0 = j0_
		}
		val x1: Int
		val y1: Int
		if (i1_ == -1 || j1_ == 0 || w[i1_].length == j1_) {
			x1 = -1
			y1 = 0
		} else {
			x1 = i1_
			y1 = j1_
		}

		i0 = x0
		j0 = y0
		i1 = x1
		j1 = y1
	}

	override fun compareTo(other: Data): Int {
		if (i0 != other.i0) {
			return i0 - other.i0
		}
		if (i1 != other.i1) {
			return i1 - other.i1
		}
		if (j0 != other.j0) {
			return j0 - other.j0
		}
		return j1 - other.j1
	}
}

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
    val m = nextInt()

	w = Array<String>(n) { next() }

	val se = TreeSet<Data>();
	val froms = mutableListOf<Data>()
	val tos = mutableListOf<Data>()

	for (i in 0 .. n-1) {
		for (j in 0 .. n-1) {
			for (sh in -5 .. 5) {
				var cnt = 0
				var ok = true
				for (k in 0 .. w[i].length - 1) {
					if (0 <= k + sh && k + sh < w[j].length) {
						cnt++
						if (w[i][k] != w[j][k+sh]) {
							ok = false
							break
						}
					}
				}

				if (cnt > 0 && ok) {
					for (k in 0 .. w[i].length - 1) {
						if (0 <= k + sh && k + sh < w[j].length) {
							val from = Data(i, k, j, k+sh)
							val dummy = Data(i, k, j, k+sh, false)
							if (from.compareTo(dummy) == 0) {
								val to = Data(i, k+1, j, k+sh+1)
								se.add(from)
								se.add(to)
								froms.add(from)
								tos.add(to)
							}
						}
					}
				}
			}
		}
	}

	if (se.isEmpty()) {
		println(0)
	} else {
		val mp = TreeMap<Data, Int>()
		se.forEach { d ->
			val sz = mp.size
			mp.put(d, sz)
		}
		var g = List(se.size) { IntArray(se.size) { 0 } }
		repeat(froms.size) { i ->
			val f = mp.get(froms[i])
			val t = mp.get(tos[i])
			if (f != null && t != null) {
				g[t][f] += 1
			}
		}
		var x = IntArray(se.size) { 0 }
		var aux = IntArray(se.size) { 0 }
		x[0] = 1
		var tmp = List(se.size) { IntArray(se.size) { 0 } }

		var ms = m
		while (ms > 0) {
			if (ms % 2 == 1) {
				repeat(se.size) { i ->
					aux[i] = 0
					repeat(se.size) { j ->
						aux[i] = add(aux[i].toLong(),
						             mul(g[i][j].toLong(), x[j].toLong())).toInt()
					}
				}
				repeat(se.size) { i -> x[i] = aux[i] }
			}
			ms /= 2
			if (ms == 0) break
			repeat(se.size) { i-> repeat(se.size) { j->
				tmp[i][j] = 0
			}}
			repeat(se.size) { i-> repeat(se.size) { j-> repeat(se.size) { k->
					tmp[i][k] = add(tmp[i][k].toLong(),
				                mul(g[i][j].toLong(), g[j][k].toLong())).toInt()
			}}}
			repeat(se.size) { i-> repeat(se.size) { j->
				g[i][j] = tmp[i][j]
			}}
		}

		println(x[0])
	}
}