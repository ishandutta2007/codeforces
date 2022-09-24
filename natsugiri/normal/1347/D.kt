import java.util.*

fun main(argv : Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat (t) {
		val n = nextInt()
		val a = IntArray(n) { nextInt() }
		var cnt = 0
		var i = 0
		var j = n - 1
		var prv = 0
		var alice = 0
		var bob = 0
		while (true) {
			if (i > j) break
			var sum = 0
			while (i <= j && sum <= prv) {
				sum += a[i]
				i++
			}
			cnt++
			alice += sum
			prv = sum

			if (i > j) break
			sum = 0
			while (i <= j && sum <= prv) {
				sum += a[j]
				j--
			}
			cnt++
			bob += sum
			prv = sum
		}

		println("$cnt $alice $bob")
	}
}