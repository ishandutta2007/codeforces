import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val t = nextInt()
	repeat(t) {
		val a = nextInt()
		val b = nextInt()
		sb.appendLine(a+b)
	}
	print(sb)
}