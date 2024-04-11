import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val m = nextInt()

		val a = LongArray(n) { 0L }
		val xs = mutableListOf<Int>()
		val ys = mutableListOf<Int>()
		val ws = mutableListOf<Long>()

		repeat(m) {
			val x = nextInt() - 1
			val y = nextInt() - 1
			val w = nextLong()

			a[x] = maxOf(a[x], w)
			a[y] = maxOf(a[y], w)

			xs.add(x)
			ys.add(y)
			ws.add(w)
		}

		var yes = true
		repeat(m) {
			val x = xs[it]
			val y = ys[it]
			val w = ws[it]

			if (w != minOf(a[x], a[y])) {
				yes = false
			}
		}

		if (yes) {
			println("YES")
			println(a.joinToString(" "))
		} else {
			println("NO")
		}
    }
}