import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = nextInt()
		val va = nextInt()
		val c = nextInt()
		val vc = nextInt()
		val b = nextInt()

		val ans = maxOf(va, vc - c + b)
		sb.appendLine(ans)
	}
	print(sb)
}