fun main(argv: Array<String>) {
	val n = readLine()!!.toInt()
	val s = readLine()!!
	var ans = 0
	var cnt = 0
	s.forEach {
		if (it == 'x') {
			if (cnt == 2) {
				ans++
			} else {
				cnt++
			}
		} else {
			cnt = 0;
		}
	}
	println(ans)
}