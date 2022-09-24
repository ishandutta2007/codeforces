import java.util.*
import kotlin.math.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = Array(n) { Pair(nextInt(), it) }
		val b = Array(n) { Pair(nextInt(), it) }
		a.sortBy { it.first }
		b.sortBy { it.first }
		var best = 0
		var bests = 0
		for (s in 0 .. n-1) {
			var tmp = Int.MAX_VALUE
			var j = s
			for (i in 0 .. n-1) {
				tmp = minOf(tmp, abs(a[i].first - b[j].first))
				j++
				if (j == n) j = 0
			}
			if (best < tmp) {
				best = tmp
				bests = s
			}
		}
		val ans = IntArray(n) { 0 }
		var j = bests
		for (i in 0 .. n-1) {
			ans[a[i].second] = b[j].second + 1
			j++
			if (j == n) j = 0
		}
		println(ans.joinToString(" "))
	}
}