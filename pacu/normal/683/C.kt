fun main(args: Array<String>) {
    val l: List<String> = readLine()!!.split(' ')
    val li: MutableList<Int> = arrayListOf()
    var n = Integer.parseInt(l[0])
    var i = 0
    while(i<n)
        li.add(Integer.parseInt(l[(i++)+1]))


    val l2: List<String> = readLine()!!.split(' ')
    val li2: MutableList<Int> = arrayListOf()
    var n2 = Integer.parseInt(l2[0])
    var i2 = 0
    while(i2<n2)
        li2.add(Integer.parseInt(l2[(i2++)+1]))
    
    val ans: MutableList<Int> = arrayListOf()
    
    var j = -1000
    while(j<=1000)
    {
        var in1 = 0
        i=0
        while(i<n)
            if(li[i++]==j)
                in1 = 1
        var in2 = 0
        i2=0
        while(i2<n2)
            if(li2[i2++]==j)
                in2 = 1
        if(in1 != in2)
            ans.add(j)
        j++
    }
    print(ans.size)
    print(" ")
    var k=0
    while(k<ans.size)
    {
        print(ans[k++])
        print(" ")
    }
    println()
}