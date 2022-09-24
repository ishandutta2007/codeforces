import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	val s = next()
	var a = '0'
	var b = '0'
	var ans = 0
	repeat(n) { i ->
		if (a == 'x' && b == 'x' && s[i] == 'x') {
			ans++
		} else {
			a = b
			b = s[i]
		}
	}
	println(ans)
}