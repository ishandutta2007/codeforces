import java.util.*

val dy = intArrayOf(0, 1, 0, -1)
val dx = intArrayOf(1, 0, -1, 0)

fun main() = with(Scanner(System.`in`)) {
    val tc = nextInt()
	val sb = StringBuilder()
	repeat(tc) {
		val n = nextInt()
		val m = nextInt()

		val a = Array(n) { IntArray(m) {0} }

		for (i in 0 .. n-1) {
			for (j in 0 .. m-1) {
				a[i][j] = nextInt()
			}
			// println(a[i].joinToString(" "))
		}

		val use = Array(n) { BooleanArray(m) { false } }

		fun inside(y: Int, x: Int): Boolean {
			return 0 <= y && y < n && 0 <= x && x < m
		}

		val ord = mutableListOf<Int>()

		fun dfs(i: Int, j: Int) {
			ord.add(a[i][j])
			use[i][j] = true

			repeat(4) rep@{ d->
				val yy = i + dy[d]
				val xx = j + dx[d]
				if (inside(yy, xx) && !use[yy][xx] && a[yy][xx] > 0) {
					dfs(yy, xx)
					ord.add(a[i][j])
				}
			}
		}

		var yes = true

		for (i in 0 .. n-1) {
			for (j in 0 .. m-1) {
				if (yes && a[i][j] > 0 && !use[i][j]) {
					if (ord.size > 0) {
						yes = false
					} else {
						dfs(i, j)
					}
				}
			}
		}


		if (yes) {
			// sb.appendLine(ord.joinToString(" "))

			val mid = ord.size / 2
			val h = mid + 1
			val w = ord.size - mid
			sb.append(h)
			sb.append(' ')
			sb.appendLine(w)
			for (i in 0 .. h-1) {
				for (j in 0 .. w-1) {
					sb.append(ord[mid + j - i])
					if (j == w-1) sb.append('\n')
					else sb.append(' ')
				}
			}
		} else {
			sb.append("-1\n")
		}
	}
	print(sb)
}