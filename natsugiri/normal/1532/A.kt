import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val sb = StringBuilder()
	repeat(n) {
		val x = nextLong()
		var y = nextLong()
		var ans = x + y
		sb.appendLine(ans)
	}
	print(sb)
}