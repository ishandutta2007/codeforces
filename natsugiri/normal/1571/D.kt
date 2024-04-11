import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()

	val mp = mutableMapOf<Int, Int>()
	val fa = IntArray(n) { 0 }
	val la = IntArray(n) { 0 }

	var myf = nextInt() - 1
	var myl = nextInt() - 1
	repeat(m-1) {
		val f = nextInt() - 1
		val l = nextInt() - 1

		fa[f]++
		la[l]++
		val key = f * 1000 + l
		val tmp = mp[key]
		if (tmp == null) {
			mp[key] = 1
		} else {
			mp[key] = tmp + 1
		}
	}

	var ans = 1
	for (f in 0 .. n-1) {
		for (l in 0 .. n-1) {
			if (f == l) {
				continue
			}

			val key = f * 1000 + l
			val c2 = mp[key] ?: 0
			val c1 = fa[f] + la[l] - c2 * 2
			val my: Int
			if (myf == f && myl == l) {
				my = 1
			} else if (myf == f || myl == l) {
				my = c2 + 1
			} else {
				my = c1 + c2 + 1
			}
			ans = maxOf(ans, my)
		}
	}

	println(ans)
}