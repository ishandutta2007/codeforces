import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val s = next()
		var ans = 0
		var cnt = 0
		for (i in 0 .. s.length - 1) {
			if (s[i] == 'w') {
				ans += cnt / 2
				cnt = 0
				ans++
			} else {
				cnt++
			}
		}
		ans += cnt / 2
		println(ans)
	}
}