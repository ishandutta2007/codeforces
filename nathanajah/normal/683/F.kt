import kotlin.comparisons.*;
fun main(args: Array<String>) {
    val s = readLine()!!
    var lastnonws = '.'
    var inword = false
    var first = true
    for (i in s) {
        if (i == ' ') {
            inword = false
        } else {
            if (i == ',') {
                print(",")
                inword = false
            } else if (i == '.') {
                print(".")
                inword = false
            } else {
                if (!inword) {
                    if (!first) {
                        print(" ")
                    }
                    first = false
                }
                var lowcase = i.toLowerCase()
                var upcase = i.toUpperCase()
                if (lastnonws == '.') {
                    print(upcase)
                } else {
                    print(lowcase)
                }
                inword = true
            }
            lastnonws = i
            
        }
    }
    println()
}