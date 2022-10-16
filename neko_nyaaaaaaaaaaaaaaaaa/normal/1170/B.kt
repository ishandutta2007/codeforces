import java.util.*

fun main() {
    val reader = Scanner(System.`in`)
    val n = reader.nextLine().toInt()
    
    var answer = 0
    var m1 = 0
    var m2 = 0
    repeat(n) {
        val x = reader.nextInt()
        
        if (m1 > x && m2 > x) {
            answer = answer + 1
        } else if (x > m1) {
            m2 = m1
            m1 = x
        } else if (x > m2) {
            m2 = x
        }
    }
    print(answer)
}