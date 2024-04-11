import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		var n = nextInt()
		var tail = 0
		var cnt = 0
		while (n >= 1000 && cnt < 2) {
			tail = n % 1000
			n /= 1000
			cnt++
		}
		if (tail >= 500) n++
		if (n >= 1000 && cnt < 2) {
			n /= 1000
			cnt++
		}
		print(n)
		if (cnt == 0) println()
		if (cnt == 1) println("K")
		if (cnt == 2) println("M")
	}
}