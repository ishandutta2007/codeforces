
fun main(args:Array<String>) {
    val a = readLine()!!.toInt()
    val mass = readLine()!!.split(" ").map{ it.toLong()}
    val f = mass.max()!!
    var ans = 0L
    for (i in 0 until a){
        if (mass[a-1-i]==f){
            ans = (a*(mass[a-i-1]-1)+a-i)
            break
        }
    }
    println(ans)
}