fun main(argv: Array<String>) {
	val a = readLine()!!.split(' ').map { it.toInt() }.sorted();
	println("%d %d %d".format(a[3]-a[0], a[3]-a[1], a[3]-a[2]))
}