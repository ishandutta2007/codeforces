fun main(argv: Array<String>) {
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(' ').map { it.toInt() };
	val b = mutableListOf<Int>()
	repeat(a.size) { i ->
		var yes = true
		for (j in i+1 .. n-1) {
			if (a[i] == a[j]) yes = false;
		}
		if (yes) b.add(a[i])
	}
	println(b.size)
	println(b.joinToString(" "))
}