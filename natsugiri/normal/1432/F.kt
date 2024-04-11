import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val m = nextInt()
	val d = nextInt()
	val a = IntArray(m) { nextInt() }
	var sum = 0
	a.forEach { sum += it }
	val sp = (d - 1) * (m + 1)
	val v = mutableListOf<Int>()
	if (n <= sum + sp) {
		println("YES")
		var h = n - sum
		if (n > 0) {
			val g = minOf(d-1, h)
			repeat(g) { v.add(0) }
			h -= g
		}
		repeat(m) { i ->
			repeat(a[i]) { v.add(i + 1) }
			val g = minOf(d-1, h)
			repeat(g) { v.add(0) }
			h -= g
		}
		println(v.joinToString(" "))
	} else {
		println("NO")
	}
}