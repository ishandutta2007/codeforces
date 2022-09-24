import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val a = nextInt()
		val b = a / 2 + 1
		println(a - b)
	}
}