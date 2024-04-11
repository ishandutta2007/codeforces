fun main(args:Array<String>) {
    val a = readLine()!!.toInt()
    for (i in 0 until a) {
        val n = readLine()!!.toInt()
        val arr = readLine()!!.split(" ").map { it.toInt() }
        val x = IntArray(n) {0}
        var mx = arr.max()!!.plus(1)
        var ind = 0
        var sumx = 0
        for (i in arr.indices) {
            if (arr[i] > 0) {
                x[i]++
                sumx += arr[i]
            }
            if (((arr[i] > 0) and (arr[i] < mx)) or ((arr[i] < 0) and (-arr[i] < mx))) {
                if (arr[i] < 0) {
                    mx = -arr[i]
                } else {
                    mx = arr[i]
                }
                ind = i
            }
        }
        if (arr[ind] < 0) {
            sumx += arr[ind]
            x[ind]++
        } else {
            x[ind]--
            sumx -= arr[ind]
        }
        println(sumx)
        for (element in x){
            print("$element")
        }
        println()
    }
}