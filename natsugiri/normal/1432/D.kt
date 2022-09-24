import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = nextInt()
		val b = nextInt()
		repeat(n) { i ->
			if (i % a < b) print('a' + i % a)
			else print('a')
		}
		println("")
	}
}