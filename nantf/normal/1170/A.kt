fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        var arr=readInts()
        var x=arr[0]
        var y=arr[1]
        var a=min(x,y)-1
        println("$a ${x-a} ${y-a}")
    }
}