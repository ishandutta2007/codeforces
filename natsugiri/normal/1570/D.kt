import java.util.*

fun main() = with(Scanner(System.`in`)) {
	var n = nextLong()
	var cnt = 0
	val se = mutableSetOf<Long>()

	while (cnt <= 10) {
		if (n < 10) {
			cnt++
		}
		se.add(n)
		n++
		while (n % 10 == 0L) {
			n /= 10
		}
	}
	print(se.size)
}