
fun main(args:Array<String>) {
    val a = readLine()!!.toInt()
    val st: List<Int> = (readLine()!!.split(" ").map{it.toInt()})
    val ff: MutableList<Int> = mutableListOf()
    for (i in 0 until a){
        if (!(ff.contains(st[i]))){
            ff+=st[i]
        }
    }
    val x = ff.sorted()
    if (x.size>2){
        print("${st.indexOf(x[0])+1} ${st.indexOf(x[1])+1} ${st.indexOf(x[2])+1}")
    } else{
        println("-1 -1 -1")
    }

}