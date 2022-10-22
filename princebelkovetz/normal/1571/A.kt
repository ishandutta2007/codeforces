fun main() {
    var tt = readLine()!!.toInt()
    while (tt-->0) {
        val s = readLine()!!
        var w1 = 0
        var w2 = 0
        for (i in 0 until s.length) {
            if (s[i] == '>') w1 = 1;
            if (s[i] == '<') w2 = 1;
        }
        if (w1 > 0 && w2 > 0) {
            println("?");
        }
        else if (w1 > 0){
            println(">")
        }
        else if (w2 > 0){
            println("<")
        }
        else {
            println("=")
        }
    }
 
}