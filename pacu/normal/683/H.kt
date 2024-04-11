fun main(args: Array<String>) {
    var (n,k) = readLine()!!.split(' ').map(String::toLong)
    val l: List<String> = readLine()!!.split(' ')
    val li: MutableList<Int> = arrayListOf()
    var i = 0
    while(i<n)
        li.add(Integer.parseInt(l[i++]))
    
    var perm: MutableList<Int> = arrayListOf()
    i = 0
    while(i<n)
    {
        perm.add(0)
        i++
    }
    i = 0
    while(i<n)
    {
        perm[li[i]-1] = i
        i++
    }
    
    var vis: MutableList<Int> = arrayListOf()
    i=0
    while(i<n)
    {
        vis.add(0)
        i++
    }
    
    var ans: MutableList<Int> = arrayListOf()
    i=0
    while(i<n)
    {
        ans.add(0)
        i++
    }
    
    i=0
    while(i<n)
    {
        if(vis[i]==0)
        {
            var cyc: MutableList<Int> = arrayListOf()
            vis[i] = 1
            cyc.add(i)
            var j = perm[i]
            var len = 1
            while(j != i)
            {
                len++
                cyc.add(j)
                vis[j] = 1
                j = perm[j]
            }
            j = 0
            while(j < cyc.size)
            {
                ans[cyc[j]] = cyc[((j.toLong()+k)%cyc.size).toInt()]
                j++
            }
        }
        i++
    }
    
    
    
    
    i=0
    while(i<n)
    {
        print(ans[i]+1)
        print(" ")
        i++
    }
    println()
}