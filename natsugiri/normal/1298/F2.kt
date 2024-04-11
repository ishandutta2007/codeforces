fun add(a: IntArray, i_: Int, v: Int) {
	var i = i_
	while (i < a.size) {
		a[i] += v
		i = i or (i+1)
	}
}
fun sum(a: IntArray, r_: Int): Int {
	var r = r_
	var ret = 0
	while (r > 0) {
		ret += a[r-1]
		r = r and (r-1)
	}
	return ret
}
fun main(argv: Array<String>) {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
	val a = readLine()!!.split(' ').map { it.toInt() }

	val base = 220000
	val f = IntArray(base*2)
	var s = 0
	var ans = n.toLong() * (n+1) / 2L

	add(f, base+s, 1)
    a.forEach {
        if (m < it) {
            s++
        } else {
            s--
		}
		add(f, base+s, 1)
	}
    s = 0
    a.forEach {
		add(f, base+s, -1)
		ans -= sum(f, f.size) - sum(f, base+s+1)
        if (m < it) {
			s++
		} else {
			s--
		}
	}
	repeat(f.size) { f[it] = 0 }

	s = 0
	add(f, base+s, 1)
    a.forEach {
        if (m <= it) {
            s++
        } else {
            s--
		}
		add(f, base+s, 1)
	}
    s = 0
    a.forEach {
		add(f, base+s, -1)
		ans -= sum(f, base+s+1)
        if (m <= it) {
			s++
		} else {
			s--
		}
	}

    println(ans)
}