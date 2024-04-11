fun main(argv: Array<String>) {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
	val r = readLine()!!.split(' ').map { it.toInt() }
	var c = IntArray(n)
	repeat(m) {
		val (x, y) = readLine()!!.split(' ').map { it.toInt()-1 }
		if (r[x] > r[y]) c[x]--
		if (r[y] > r[x]) c[y]--
	}

	val idx = IntArray(n) { it }.sortedBy({ r[it] })
	var i = 0
	while (i < n) {
		var j = i
		while (j < n && r[idx[i]] == r[idx[j]]) {
			c[idx[j]] += i
			j++
		}
		i = j
	}

	println(c.joinToString(" "))
}