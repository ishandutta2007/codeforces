import java.util.*

fun main(argv : Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat (t) {
		val a = nextInt()
		val b = nextInt()
		val c = nextInt()
		val d = nextInt()
		if (minOf(a, b) + minOf(c, d) == maxOf(a, b) && maxOf(a, b) == maxOf(c, d)) {
			println("Yes")
		} else {
			println("No")
		}
	}
}