import java.util.*

fun main(argv : Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat (t) {
		val a = nextInt()
		val b = nextInt()
		println(a + b)
	}
}