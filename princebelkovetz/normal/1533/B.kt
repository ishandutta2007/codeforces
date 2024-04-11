fun main() {
    var tt = readLine()!!.toInt()
    while (tt-- > 0) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        var c = false
        for (i in 0 until n - 1) {
            if (a[i] % 2 == a[i + 1] % 2)
                c = true;
        }
        if (c) println("YES")
        else println("NO")

    }

}