import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val a = IntArray(100) { it+1 }
	println("? %s".format(a.joinToString(" ")))
	System.`out`.flush()
	val hi = nextInt() and (127 * 128)

	repeat(100) { i ->
		a[i] *= 128
	}
	println("? %s".format(a.joinToString(" ")))
	System.`out`.flush()
	val lo = nextInt() and 127
	println("! %d".format(hi + lo))
}