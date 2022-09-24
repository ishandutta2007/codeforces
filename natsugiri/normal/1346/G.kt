import java.util.*

fun gcd(x_: Int, y_: Int): Int {
	var x = x_
	var y = y_
	while (true) {
		if (x == 0) return y
		y %= x
		if (y == 0) return x
		x %= y
	}
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val k = nextInt()
	val n = nextInt()
	val p = IntArray(k) { nextInt() }
	val x = IntArray(n) { nextInt() }

	var A = listOf<Int>()
	var B = listOf<Int>()
	var yes = false

	if (n <= 2) {
		yes = true
		A = listOf(x[0], p[0])
		if (n >= 2) {
			B = listOf(x[1], p[0])
		} else {
			B = listOf(x[0], p[0])
		}
	} else {

		val rest = IntArray(n) {0}
		var len: Int

		fun calc(start: Int, period: Int): Boolean {

			len = 0
			var time = start
			var idx = 0
			while (idx < x.size) {
				while (idx < x.size && x[idx] < time) {
					rest[len] = x[idx]
					len++
					idx++
				}
				if (idx < x.size && x[idx] == time) {
					idx++
				}

				if (idx >= x.size) break
				time += (x[idx] - time + period - 1) / period * period
			}

			if (len <= 1) {
				A = listOf(start, period)
				if (len == 0) {
					B = listOf(start, period)
				} else {
					B = listOf(rest[0], period)
				}
				return true
			}

			var g = 0
			for (i in 0..len-2) {
				g = gcd(g, rest[i+1] - rest[i])
			}

			for (i in 0 .. p.size-1) {
				if (g % p[i] == 0) {
					A = listOf(start, period)
					B = listOf(rest[0], p[i])
					return true
				}
				if (g < p[i]) break
			}
			return false
		}

		for (i in 0 .. p.size-1) {
			if ((x[1] - x[0]) % p[i] == 0 || (x[2] - x[0]) % p[i] == 0) {
				yes = calc(x[0], p[i])
				if (yes) break
			}
			if ((x[2] - x[1]) % p[i] == 0 && (x[1] - x[0]) % p[i] != 0) {
				yes = calc(x[1], p[i])
				if (yes) break
			}
		}
	}

	if (yes) {
		println("YES")
		println(A.joinToString(" "))
		println(B.joinToString(" "))
	} else {
		println("NO")
	}
}