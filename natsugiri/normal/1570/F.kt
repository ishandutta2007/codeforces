import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
    val n = nextInt()
	val m = nextInt()
	val a = Array<IntArray>(n) { IntArray(m) {0} }
	val b = Array<IntArray>(n) { IntArray(m) {0} }
	repeat(n) { i ->
		repeat(m) { j ->
			a[i][j] = nextInt()
		}
	}

	val R = mutableListOf<Int>()
	val C = mutableListOf<Int>()

	repeat(n-1) { i ->
		repeat(m-1) { j ->
			if (a[i][j] == 1 && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1 &&
			  (b[i][j] == 0 || b[i][j+1] == 0 || b[i+1][j] == 0 || b[i+1][j+1] == 0)) {
			    b[i][j] = 1
			    b[i][j+1] = 1
			    b[i+1][j] = 1
			    b[i+1][j+1] = 1
				R.add(i)
				C.add(j)
			}
		}
	}


	repeat(n) { i ->
		repeat(m) { j ->
			if (a[i][j] != b[i][j]) {
				println(-1)
				return
			}
		}
	}
	sb.appendLine(R.size)
	repeat(R.size) { i ->
		sb.appendLine("%d %d".format(R[i]+1, C[i]+1))
	}
	print(sb)
}