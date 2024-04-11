import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val k = nextInt()
	val a = LongArray(n) { nextLong() }
	a.sort()
	val sums = LongArray(n+1) { 0L }
	for (i in 0 .. n-1) {
		sums[i+1] = sums[i] + a[i]
	}

	val dp = Array(n+1) { LongArray(k+1) { -10000000000L } }
	dp[0][0] = 0L
	for (i in 0 .. n-1) {
		for (x in 0 .. k) {
			dp[i+1][x] = maxOf(dp[i+1][x], dp[i][x])
		}

		var s = 1
		while (i + s + s <= n && 0 <= k-s) {
			for (x in 0 .. k-s) {
				val tmp = dp[i][x] + sums[i+s+s] - sums[i+s] - sums[i+s] + sums[i];
				dp[i+s+s][x+s] = maxOf(dp[i+s+s][x+s], tmp)
			}
			s++
		}
	}
	println(dp[n][k])
}