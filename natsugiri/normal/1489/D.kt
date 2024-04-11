import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val w = Array(n) { next() }
	w.sortBy { it.length }

	var yes = true
	repeat(n-1) { i->
		if (!w[i+1].contains(w[i])) {
			yes = false
		}
	}
	if (yes) {
		println("YES")
		println(w.joinToString("\n"))
	} else {
		println("NO")
	}
}