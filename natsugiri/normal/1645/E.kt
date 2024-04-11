import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
	val k = nextInt()
	val a = mutableListOf<Int>()
	for (t in 0 .. 30) if ((n.shr(t) and 1) != 0) {
		a.add(1.shl(t))
	}

	var i = 0
	while (i < a.size) {
		if (a[i] == 1) {
			i++
		} else if (a.size < k) {
			a[i] /= 2
			a.add(a[i])
		} else {
			break
		}
	}

	if (a.size == k) {
		sb.appendLine("YES")
		sb.appendLine(a.joinToString(" "))
	} else {
		sb.appendLine("NO")
	}
	print(sb)
}