import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
	val m = nextInt()
	val se = HashSet<String>()
	repeat (n) {
		se.add(next())
	}

	val q = nextInt()
	repeat(q) {
		val t = next()
		var ans = HashSet<String>()
		repeat (m+1) { i ->
			val g = t.substring(0, i) + t.substring(i+1, m+1)
			if (se.contains(g)) {
				ans.add(g)
			}
		}
		sb.appendLine(ans.size)
	}
	print(sb)
}