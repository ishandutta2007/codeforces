import java.util.Scanner

fun main(vararg args: String) {
    val input = Scanner(System.`in`)
    val n = input.nextInt()
    val a = Array(n, {0})
    var z = 0
    while (z < n) {
        a[z] = input.nextInt()
        z += 1
    }
    var siz = -1
    var tmp = 0
    var i = 0
    var flag = 0
    while (i < n) {
        if ((i == 0) || (i > 0 && a[i] == a[i-1])) {tmp += 1}
        else {
            if (siz == -1) {siz = tmp}
            else if (siz != tmp) {
                flag = 1
                break
            }
            tmp = 1
        }
        i += 1
    }
    if (siz == -1) {siz = tmp}
    else if (siz != tmp) {
        flag = 1
    }
    if (flag == 1) println("NO")
    else println("YES")
}