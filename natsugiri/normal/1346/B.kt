import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextLong()
		val k1 = nextLong()
		val k2 = nextLong()
		val s = next()

		var ans = 0L
		var prv = 0L

		s.forEach {
			if (it == '0') {
				prv = 0
			} else {
				val tmp = minOf(k1, k2 - prv)
				ans += tmp
				prv = tmp
			}
		}
		println("$ans")
    }
}