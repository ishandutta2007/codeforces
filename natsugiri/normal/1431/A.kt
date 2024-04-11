import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextInt()
		val a = LongArray(n) { nextLong() }.sorted()
		var ans = 0L
		for (i in 0 .. n-1) {
			ans = maxOf(ans, (n - i) * a[i])
		}
		println(ans)
	}
}