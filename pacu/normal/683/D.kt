fun main(args: Array<String>) {
    val Q = Integer.parseInt(readLine())
    var i = 0
    while(i<Q)
    {
        val(n,m,p) = readLine()!!.split(' ').map(String::toInt)
        var r = 1
        var okay = 0
        while(r <= n)
        {
            if(p%r == 0 && p/r <= m) okay = 1
            r++
        }
        if(okay==1) println("Yes")
        else println("No")
        i++
    }
}