import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = Array(n) { Pair(nextInt(), it) }
		a.sortBy { it.first }
		var ans = ArrayList<Int>(n)
		var cnt = 0
		var k = 0
		for (i in 0 .. n-1) {
			if (cnt >= a[k].first) {
				cnt = 0
				ans.add(a[k].second + 1)
				k++
			} else {
				ans.add(-1)
			}
			cnt++
		}
		for (i in 0 .. n-1) {
			if (ans[i] == -1) {
				ans[i] = a[k].second + 1
				k++
			}
		}
		println(ans.joinToString(" "))
	}
}