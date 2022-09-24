import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
    val a = IntArray(n) { nextInt() }
	var ans = 0
    a.sort()
	repeat (n/2) { i ->
		ans += a[i*2+1] - a[i*2]
	}
	print(ans)
}