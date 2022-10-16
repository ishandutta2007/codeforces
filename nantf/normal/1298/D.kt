fun readInt()=readLine()!!.toInt()
fun readInts()=readLine()!!.split(" ").map(String::toInt)
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun main(){
    var a=readInts()
    var n=a[0]
    var w=a[1]
    a=readInts()
    var sum=0
    var mx=0
    var mn=0
    for(i in 0..n-1){
        sum+=a[i]
        mx=max(mx,sum)
        mn=min(mn,sum)
    }
    println(w-max(-1,min(w,mx-mn-1)))
}