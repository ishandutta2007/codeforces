import kotlin.comparisons.*;
fun gcd(a: Int, b:Int):Int {
    if (b == 0) {
        return a
    }
    return gcd(b, a % b)
}
fun main(args: Array<String>) {
    val s = readLine()!!
    val n = s.length
    var nonrepeat = 0
    var repeat = 0
    var nonrepeatLength =0
    var repeatingLength = 0
    var repeated = false 
    for (i in (2..n - 1)) {
        if (s[i] == '(') {
            repeated = true
        } else if (s[i] == ')') {}
        else if (repeated) {
            repeatingLength += 1
            repeat = 10 * repeat + (s[i].toInt()) - '0'.toInt()
        } else {
            nonrepeatLength += 1
            nonrepeat = 10 * nonrepeat + (s[i].toInt()) - '0'.toInt()
        }
    }
    var denom = 1
    for (i in 1..repeatingLength) {
        denom = 10 * denom
    }
    denom -= 1
    for (i in 1..nonrepeatLength) {
        denom = 10 * denom
    }
    var numer = nonrepeat
    for (i in 1..repeatingLength) {
        numer = 10 * numer
    }
    numer += repeat
    numer -= nonrepeat
    val x = gcd(numer, denom)
    print(numer/x)
    print("/")
    println(denom/x)
}