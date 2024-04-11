
fun main(args:Array<String>) {
    val a = readLine()!!.toInt()
    for (i in 0 until a){
        val f = readLine()!!.toLong()
        if (f<1000) {
            println(f)
        } else if(f<999500){
            val n = (f / 1000)
            if (f%1000>=500){
                println("${n+1}K")
            } else{
                println("${n}K")
            }
        } else{
            val n = f / 1000000
            if (f%1000000>=500000){
                println("${n+1}M")
            } else{
                println("${n}M")
            }
        }
    }
}