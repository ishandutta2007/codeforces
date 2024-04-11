import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {
		val n = nextInt()
		val p = Array<Pair<Int, Int> >(n) {
			val a = nextInt()
			Pair<Int, Int>(a, it)
		}
		p.sortBy({ it.first })
		var sum = 0L
		var negative = -1
		var positive = -1
		var ans = CharArray(n) { '0' }
		repeat(n) {
			val (a, i) = p[it]
			if (a >= 0) {
				sum += a
				ans[i] = '1'
			}
			if (a > 0 && positive == -1) positive = it
			if (a < 0) negative = it
		}

		if (negative == -1 || sum - p[positive].first >= sum + p[negative].first) {
			println(sum - p[positive].first)
			ans[p[positive].second] = '0'
			println(ans.joinToString(""))
		} else {
			println(sum + p[negative].first)
			ans[p[negative].second] = '1'
			println(ans.joinToString(""))
		}
    }
}