fun main(args: Array<String>) {
    val n = Integer.parseInt(readLine())
    val l: List<String> = readLine()!!.split(' ')
    val li: MutableList<Int> = arrayListOf()
    var i = 0
    while(i<n)
        li.add(Integer.parseInt(l[i++]))
    var j = 0
    while(j < n)
    {
        var c = n-1
        var num = n-1
        while(c>=0)
        {
            if(li[c]==0) num = c
            c--
        }
        print(num+1)
        print(" ")
        c = 0
        while(c <= num)
            li[c++]--
        j++
    }
    println()
}