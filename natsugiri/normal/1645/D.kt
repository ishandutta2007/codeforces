import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()

	val n = nextInt()
    val a = IntArray(n) { nextInt() }
	a.sort()
	val f = mutableListOf<Int>()
	val g = mutableListOf<Int>()
	var yes = true
	for (i in 0 .. n-1) {
		if (f.isEmpty() || f.last() != a[i]) {
			f.add(a[i])
		} else if (g.isEmpty() || g.last() != a[i]) {
			g.add(a[i])
		} else {
			yes = false
		}
	}

	if (yes) {
		sb.appendLine("YES")
		sb.appendLine(f.size)
		sb.appendLine(f.joinToString(" "))
		sb.appendLine(g.size)
		g.reverse()
		sb.appendLine(g.joinToString(" " ))
	} else {
		sb.appendLine("NO")
	}
	print(sb)
}