import java.util.*

fun main(argv : Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat (t) {
		var a = nextInt()
		var ten = 1
		val ans = mutableListOf<Int>();
		while (a > 0) {
			val m = a % 10
			if (m > 0) {
				ans.add(m * ten)
			}
			a /= 10
			ten *= 10
		}
		println(ans.size)
		println(ans.joinToString(" "))
	}
}