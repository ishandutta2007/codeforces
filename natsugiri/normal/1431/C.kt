import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val k = nextInt()
		val a = LongArray(n) { nextLong() }
		var ans = 0L
		val sums = LongArray(n + 1)
		for (i in 0 .. n-1) {
			sums[i+1] = sums[i] + a[i]
		}
		for (x in 1 .. n) {
			val h = x / k
			val tmp = sums[n - x + h] - sums[n - x]
			ans = maxOf(ans, tmp)
		}
		println(ans)
	}
}