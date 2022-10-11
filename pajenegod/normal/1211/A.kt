//only in it for the t-shirt
fun main() {
    var n = Integer.parseInt(readLine())
    val inp = readLine()
    if(inp != null) {
        val arr = inp.split(' ').map { e -> Integer.parseInt(e) }
        var maxi = 0
        var mini = 0
        for (i in 0 until n)
        {
            if (arr[maxi] < arr[i])
                maxi = i
            if (arr[mini] > arr[i])
                mini = i
        }
        var j = 0
        for (i in 0 until n)
            if (arr[i] != arr[mini] && arr[i] != arr[maxi])
                j = i
    
        if (arr[j] != arr[mini] && arr[j] != arr[maxi])
        {
            println(mini + 1)
            println(j + 1)
            println(maxi + 1)
        }
        else
        {
            println(-1)
            println(-1)
            println(-1)
        }
    }
}