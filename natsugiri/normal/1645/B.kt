import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val s = next()
	val ans = mutableListOf<Char>()
	var i = 0
	var cnt = 1
	while (i < s.length) {
		ans.add(s[i])
		i += cnt
		cnt++
	}
	print(ans.joinToString(""))
}