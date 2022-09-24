import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
	val t = nextInt()
	repeat(t) {
		val n = nextLong()
		val k = nextLong()

		val m = 1 + k + k*k + k*k*k
		val a = n / m
		println("$a ${a*k} ${a*k*k} ${a*k*k*k}")
    }
}