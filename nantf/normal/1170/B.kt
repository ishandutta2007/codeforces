fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

fun main(){
    var n=readInt()
    var a=readInts()
    var x1=0
    var x2=0
    var ans=0
    for(i in 0..n-1){
        if(x2>a[i]) ans++
        if(a[i]>x1){
            x2=x1
            x1=a[i]
        }
        else if(a[i]>x2) x2=a[i]
    }
    print(ans)
}