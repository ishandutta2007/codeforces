import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val tc = nextInt()
	val sb = StringBuilder()
	repeat(tc) {
		val n = nextInt()
		val a = LongArray(n) { nextLong() }

		var yes = false
		repeat (n-1) { i ->
			if (!yes && (a[i+1] - a[i]) % 2 == 0L) {
				yes = true
			}
		}

		sb.appendLine(if (yes) "YES" else "NO")
	}
	print(sb)
}