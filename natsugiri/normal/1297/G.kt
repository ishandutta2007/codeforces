import java.util.*

val LIMIT = 1000000000L
val p = listOf(1, 2, 3, 5, 7)

val mult = IntArray(5)
val dp = LongArray(1000000)

fun index(len: Int, two: Int, three: Int, five: Int, seven: Int): Int {
	if (two >= mult[1]) println("##2")
    if (three >= mult[2]) println("##3")
    if (five >= mult[3]) println("##5")
    if (seven >= mult[4]) println("##7")
    return (((len * mult[1] + two) * mult[2] + three) * mult[3] + five) * mult[4] + seven
}

fun get(len: Int, two: Int, three: Int, five: Int, seven: Int): Long {
    return dp[index(len, two, three, five, seven)]
}

fun add(len: Int, two: Int, three: Int, five: Int, seven: Int, v: Long) {
    val i = index(len, two, three, five, seven)
    dp[i] += v
    if (dp[i] > LIMIT) dp[i] = LIMIT
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val m = nextLong()
    var k = nextLong()
    val c = IntArray(5)
    var tmp = m
    for (i in 1..4) {
        while (tmp % p[i] == 0L) {
            tmp /= p[i]
            c[i]++
        }
        mult[i] = c[i] + 1
	}

    if (tmp > 1) {
        println(-1)
    } else {
        add(0, 0, 0, 0, 0, 1L)

        for (len in 0..1000000) {
			val total = get(len, c[1], c[2], c[3], c[4])
			if (total >= k) {
				var l = len
				var two = c[1]
				var three = c[2]
				var five = c[3]
				var seven = c[4]
				val ans = mutableListOf<Char>()
				while (l > 0) {
					l -= 1
					if (true) {
						var v = get(l, two, three, five, seven)
						if (v < k) { k -= v }
						else { ans.add('1'); continue }
					}

					if (two >= 1) {
						var v = get(l, two-1, three, five, seven)
						if (v < k) { k -= v }
						else { ans.add('2'); two -= 1; continue }
					}

					if (three >= 1) {
						var v = get(l, two, three-1, five, seven)
						if (v < k) { k -= v }
						else { ans.add('3'); three -= 1; continue }
					}

					if (two >= 2) {
						var v = get(l, two-2, three, five, seven)
						if (v < k) { k -= v }
						else { ans.add('4'); two -= 2; continue }
					}

					if (five >= 1) {
						var v = get(l, two, three, five-1, seven)
						if (v < k) { k -= v }
						else { ans.add('5'); five -= 1; continue }
					}

					if (two >= 1 && three >= 1) {
						var v = get(l, two-1, three-1, five, seven)
						if (v < k) { k -= v }
						else { ans.add('6'); two -=1; three -= 1; continue }
					}

					if (seven >= 1) {
						var v = get(l, two, three, five, seven-1)
						if (v < k) { k -= v }
						else { ans.add('7'); seven -= 1; continue }
					}
					if (two >= 3) {
						var v = get(l, two-3, three, five, seven)
						if (v < k) { k -= v }
						else { ans.add('8'); two -= 3; continue }
					}

					if (three >= 2) {
						var v = get(l, two, three-2, five, seven)
						if (v < k) { k -= v }
						else { ans.add('9'); three -= 2; continue }
					}

					println("#############")
				}
				// println(len)
				println(ans.joinToString(""))
				return
			} else {
				k -= total
			}

			for (two in 0..c[1]) {
                for (three in 0..c[2]) {
                    for (five in 0..c[3]) {
                        for (seven in 0..c[4]) {
							val v = get(len, two, three, five, seven)

                            add(len + 1, two, three, five, seven, v)
                            if (two + 1 <= c[1]) add(len + 1, two + 1, three, five, seven, v)
                            if (three + 1 <= c[2]) add(len + 1, two, three + 1, five, seven, v)
                            if (two + 2 <= c[1]) add(len + 1, two + 2, three, five, seven, v)
                            if (five + 1 <= c[3]) add(len + 1, two, three, five + 1, seven, v)
                            if (two + 1 <= c[1] && three + 1 <= c[2]) add(len + 1, two + 1, three + 1, five, seven, v)
                            if (seven + 1 <= c[4]) add(len + 1, two, three, five, seven + 1, v)
                            if (two + 3 <= c[1]) add(len + 1, two + 3, three, five, seven, v)
                            if (three + 2 <= c[2]) add(len + 1, two, three + 2, five, seven, v)
                        }
                    }
                }
			}
        }
    }
}