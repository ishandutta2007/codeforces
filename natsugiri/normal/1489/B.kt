import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
	val q = nextInt()
	repeat(q) {
		val n = nextLong()
		val a = nextLong()
		val b = nextLong()
		sb.appendLine(minOf(
			n*a,
			n/2*b + n%2*a
		))
	}
	print(sb)
}