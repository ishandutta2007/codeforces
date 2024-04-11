import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()

	val s = IntArray(n) { 0 }

	for (i in 1..n) {
		var j = i + i
		while (j <= n) {

			s[j-1]++
			s[i-1]--

			j += i
		}
	}
	s.sort()

	val ans = LongArray(n) { 0L }
	var sum = 0L
	repeat(n) { i ->
		ans[n-1-i] = sum
		sum -= s[i]
	}

	println(ans.joinToString(" "))
}