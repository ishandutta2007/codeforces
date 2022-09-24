import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val a = IntArray(n) { nextInt() }
	val ma = a.max()!!
	val cnt = IntArray(ma+1)
	a.forEach { cnt[it]++ }

	var ans = 0
	var prv = -1

	for (x in 1 .. ma) {
		repeat (cnt[x]) {
			if (1 < x && prv < x-1) {
				prv = x-1
				ans++
			} else if (prv < x) {
				prv = x
				ans++
			} else if (prv < x+1) {
				prv = x+1
				ans++
			}
		}
	}
	print(ans)
}