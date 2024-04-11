import java.util.*

fun main() = with(Scanner(System.`in`)) {
	val sb = StringBuilder()
	val k = nextInt()
	val s = next()
	val t = next()

	val a = IntArray(k+1)
	for (i in 0 .. k-1) {
		a[i] += s[k-1-i] - 'a'
		a[i] += t[k-1-i] - 'a'
		if (a[i] >= 26) {
			a[i] -= 26
			a[i+1]++
		}
	}

	for (i in 0 .. k) {
		if (a[i] % 2 == 0) {
			a[i] /= 2
		} else {
			a[i] /= 2
			a[i-1] += 13
		}
	}
	for (i in 0 .. k-1) {
		if (a[i] >= 26) {
			a[i] -= 26
			a[i+1]++
		}
	}

	val ans = CharArray(k) { ('a' + a[k-1-it]) }
	println(ans.joinToString(""))
}