import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val k = nextInt() - 1
	val a = IntArray(n) { m+1 }
	a[k] = 0
	repeat(m) {
		val x = nextInt() - 1
		val y = nextInt() - 1

		val g = minOf(a[x]+1, a[y])
		val h = minOf(a[x], a[y]+1)
		a[x] = g
		a[y] = h
	}

	repeat(n) {
		if (a[it] >= m+1) {
			a[it] = -1
		}
	}
	println(a.joinToString(" "))
}