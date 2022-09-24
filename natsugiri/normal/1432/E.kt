import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		var k = nextLong()
		val s = next()
		var one = 0
		val ans = ArrayList<Char>(n)
		s.forEach { c ->
			if (c == '0') {
				while (one > k) {
					ans.add('1')
					one--
				}
				k -= one
				ans.add('0')
			} else {
				one++
			}
		}
		repeat(one) {
			ans.add('1')
		}
		println(ans.joinToString(""))
	}
}