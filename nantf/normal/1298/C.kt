fun readInt()=readLine()!!.toInt()
fun readInts()=readLine()!!.split(" ").map(String::toInt)
fun max(a:Int,b:Int)=if(a>b) a else b
fun main(){
    var n=readInt()
    var s=readLine()!!
    var cnt=0
    var ans=0
    for(i in 0..n-1){
        if(s[i]=='x') cnt++
        else{
            ans+=max(cnt-2,0)
            cnt=0
        }
    }
    ans+=max(cnt-2,0)
    println(ans)
}