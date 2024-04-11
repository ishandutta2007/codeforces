import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var x = sc.nextInt()
    var y = sc.nextInt()
    var z = sc.nextInt()

    var a = sc.nextInt()
    var b = sc.nextInt()
    var c = sc.nextInt()

    if (x > a) {
        println("NO")
        return
    }
    if (y + x > a + b) {
        println("NO")
        return
    }
    if (z + y + x > a + b + c) {
        println("NO")
        return
    }
    print("YES")
}