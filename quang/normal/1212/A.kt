import java.util.*

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt();
    var k = sc.nextInt();
    for (i in 1..k) {
        if (n % 10 > 0) {
            n--;
        } else {
            n /= 10;
        }
    }
    println(n);
}