fun main(argv: Array<String>) {
    val (n, w) = readLine()!!.split(' ').map { it.toLong() }
    val a = readLine()!!.split(' ').map { it.toLong() }
    var cnt = 0L
    var mi = 0L
    var ma = 0L
    a.forEach {
        cnt += it
        ma = maxOf(ma, cnt)
        mi = minOf(mi, cnt)
	}
	// -mi <= x <= w-ma
	if (-mi > w-ma) {
		println("0")
	} else {
		println(w - ma + mi + 1)
	}
}