import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
	val sb = StringBuilder()
	repeat(t) {
		val n = nextInt()
		val k = nextInt()
		repeat(n) { i ->
			sb.append('a' + i % k)
		}
		sb.appendLine("")
	}
	print(sb)
}