fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun maxll(a:Long,b:Long)=if(a>b) a else b
fun minll(a:Long,b:Long)=if(a<b) a else b

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        var n=readInt()
        if(n<=999) println(n)
        else{
            if(n<=999499){
                if(n%1000<=499) println("${n/1000}K")
                else println("${n/1000+1}K")
            }
            else{
                if(n%1000000<=499999) println("${n/1000000}M")
                else println("${n/1000000+1}M")
            }
        }
    }
}