import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val tc = nextInt()
	repeat(tc) {
		val n = nextInt()
		val s = next()
		val a = next()

		val INF = 1000000000
		val cur = IntArray(8) { INF }
		cur[0] = 0
		repeat(n) { i ->
			val nxt = IntArray(8) { INF }
			if (i >= 3 && a[i-3] == '1') {
				val cst = (if (s[i] == '(') 1 else 0)
				// (())
				nxt[3] = minOf(nxt[3], cur[1] + cst)
				// ()()
				nxt[5] = minOf(nxt[5], cur[2] + cst)
			} else {
				for (x in 0..7) {
					if (cur[x] < INF) {
						val y = x * 2 % 8
						val z = y + 1
						if (s[i] == '(') {
							nxt[y] = minOf(nxt[y], cur[x])
							nxt[z] = minOf(nxt[z], cur[x] + 1)
						} else {
							nxt[y] = minOf(nxt[y], cur[x] + 1)
							nxt[z] = minOf(nxt[z], cur[x])
						}
					}
				}
			}

			for (x in 0..7) cur[x] = nxt[x]
		}

		val ans = cur.minOrNull()!!
		if (ans == INF) {
			sb.appendLine(-1)
		} else {
			sb.appendLine(ans)
		}
	}
	print(sb)
}