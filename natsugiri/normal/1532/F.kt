import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
	val len = 2*n-2
	val a = List<String>(len) { next() }

	val one = IntArray(n) { -1 }
	val two = IntArray(n) { -1 }
	repeat(len) { i ->
		if (one[a[i].length] == -1) {
			one[a[i].length] = i
		} else {
			two[a[i].length] = i
		}
	}

	var ans = CharArray(len) { '.' }

	fun f(guess: String): Boolean {
		var ok = true
		for (i in 1..n-1) {
			if (guess.startsWith(a[one[i]]) && guess.endsWith(a[two[i]])) {
				ans[one[i]] = 'P'
				ans[two[i]] = 'S'
			} else if (guess.startsWith(a[two[i]]) && guess.endsWith(a[one[i]])) {
				ans[one[i]] = 'S'
				ans[two[i]] = 'P'
			} else {
				ok = false
				break
			}
		}
		return ok
	}

	val guess1 = a[one[n-1]] + a[two[n-1]][n-2]
	val guess2 = a[two[n-1]] + a[one[n-1]][n-2]
	if (f(guess1)) {
		print(ans)
	} else if (f(guess2)) {
		print(ans)
	} else {
		print("No")
	}
}