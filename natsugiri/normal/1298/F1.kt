fun main(argv: Array<String>) {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
	val a = readLine()!!.split(' ').map { it.toInt() }
	val base = 220000
	val mp = IntArray(base*2)
	var s = 0
	mp[base + s]++
    a.forEach {
        if (m <= it) {
            s++
        } else {
            s--
		}
		mp[base + s]++
	}
    s = 0
	var offset = 0
	var ans = 0L
	repeat(n) { i ->
		mp[base + s]--
		if (m <= a[i]) {
            s++
            offset--
        } else {
            s--
            offset++
		}

        if (a[i] == m) {
			ans += mp[base - offset]
			ans += mp[base - offset + 1]
			var j = i-1
			var t = 0
            while (j >= 0 && a[j] != m) {
				if (a[j] <= m) {
					t--
				} else {
					t++
				}
				ans += mp[base - t - offset]
				ans += mp[base - t - offset + 1]
                j--
            }
        }
    }

    println(ans)
}