import java.util.*

fun main(argv : Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()

	repeat (t) {
		val n = nextInt()
		if (n <= 3) {
			println("-1")
		} else {
			val ans = mutableListOf<Int>()
			var i = n
			if (n % 2 == 0) i--
			while (i >= 1) {
				ans.add(i)
				i -= 2
			}
			ans.add(4)
			ans.add(2)
			i = 6
			while (i <= n) {
				ans.add(i)
				i += 2
			}
			println(ans.joinToString(" "))
		}
	}
}