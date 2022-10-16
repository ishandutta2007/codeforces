fun readInt()=readLine()!!.toInt()
fun readInts()=readLine()!!.split(" ").map(String::toInt)
fun main(){
    var a=readInts()
    a=a.sorted()
    println("${a[3]-a[0]} ${a[3]-a[1]} ${a[3]-a[2]}")
}