import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		var s = 0
		repeat(n) {
			s += nextInt()
		}
		println((s + n - 1) / n)
	}
}