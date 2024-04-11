import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
    val a = IntArray(n) { nextInt() }


	val INF = 1000000000
	val dpID = IntArray(n) { -INF }
	val dpDI = IntArray(n) { INF }
	val prvID = CharArray(n) { '?' }
	val prvDI = CharArray(n) { '?' }

	dpID[0] = INF
	dpDI[0] = -INF
	for (i in 1 .. n-1) {
		if (a[i-1] < a[i] && dpID[i] < dpID[i-1]) {
			dpID[i] = dpID[i-1]
			prvID[i] = 'I'
		}
		if (dpDI[i-1] < a[i] && dpID[i] < a[i-1]) {
			dpID[i] = a[i-1]
			prvID[i] = 'D'
		}
		if (a[i-1] > a[i] && dpDI[i] > dpDI[i-1]) {
			dpDI[i] = dpDI[i-1]
			prvDI[i] = 'D'
		}
		if (dpID[i-1] > a[i] && dpDI[i] > a[i-1]) {
			dpDI[i] = a[i-1]
			prvDI[i] = 'I'
		}
	}

	var c = '?'
	var i = n-1
	if (dpID[i] >= 0) {
		c = 'I'
	} else if (dpDI[i] < INF) {
		c = 'D'
	}
	if (c == '?') {
		sb.appendLine("NO")
	} else {
		val ans = IntArray(n) { 0 }

		while (true) {
			if (c == 'I') {
				ans[i] = 0
				c = prvID[i]
			} else {
				ans[i] = 1
				c = prvDI[i]
			}
			if (i == 0) break
			i--
		}
		sb.appendLine("YES")
		sb.appendLine(ans.joinToString(" "))
	}

	print(sb)
}