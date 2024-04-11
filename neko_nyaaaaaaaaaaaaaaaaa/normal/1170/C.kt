import java.util.*

fun main() {
    val reader = Scanner(System.`in`)
    val tc = reader.nextLine().toInt()
    
    for (testcase in 1..tc) {
        val s = reader.nextLine()
        val t = reader.nextLine()
        
        var i = 0
        var j = 0
        
        var yes = 1
        while (j < t.length) {
            if (i >= s.length) {
                yes = 0
                break
            }
            if (s[i] == t[j]) {
                i = i+1
                j = j+1
            } else if (i+1 < s.length && s[i] == '-' && s[i+1] == '-' && t[j] == '+') {
                i = i+2
                j = j+1
            } else {
                yes = 0
                break
            }
        }
        
        if (yes == 1 && i == s.length && j == t.length) {
            println("YES")
        } else {
            println("NO")
        }
    }
}