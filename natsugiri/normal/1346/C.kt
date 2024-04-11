import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextLong()
		val k = nextLong()
		val x = nextLong()
		val y = nextLong()

		val a = LongArray(n.toInt()) { nextLong() }
		a.sortDescending()
		var sum = 0L
		a.forEach { sum += it }

		var ans = x * n
		var cst = 0L
		a.forEach {
			if ((sum + n - 1) / n <= k) {
				val tmp = cst + y
				ans = minOf(ans, tmp)
			}

			if (sum / n == k) {
				val tmp = cst + y + sum % n * x
				ans = minOf(ans, tmp)
			}

			if (it <= k) {
				ans = minOf(ans, cst)
			}

			sum -= it
			cst += x
		}

		println("$ans")
    }
}