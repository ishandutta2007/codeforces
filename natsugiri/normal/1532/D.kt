import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val a = IntArray(n) { nextInt() }
	a.sort()
	var ans = 0
	repeat(n/2) { i ->
		ans += a[i*2+1] - a[i*2]
	}
	print(ans)
}