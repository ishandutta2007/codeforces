fun main() {
    var tt = readLine()!!.toInt()
    while (tt-- > 0) {
        val (n, k) = readLine()!!.split(" ").map {it.toInt()}
        val s = readLine()!!
        var sweets = mutableListOf<Int>()
        for (i in 0 until n)
            sweets.add(i)

        var ans = 0
        var cur = 0
        while (true) {
            var c = false
            for (x in sweets){
                if (s[x] == '1') c = true;
            }
            if (!c) break
            val sweets2 = mutableListOf<Int>()
            for (i in 0 until sweets.size){
                if (i == cur) continue
                sweets2.add(sweets[i])
            }
            sweets = sweets2
            if (sweets.isNotEmpty())
                cur = (cur + k - 1 + sweets.size) % sweets.size
            ans++
        }
        println(ans)

    }

}