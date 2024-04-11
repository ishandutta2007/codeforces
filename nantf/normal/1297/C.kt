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
        var a=readInts()
        var s=IntArray(n){0}
        var mn=1000000000
        var sum=0
        for(i in 0..n-1){
            if(a[i]>0){
                sum+=a[i]
                s[i]=1
                mn=min(mn,a[i])
            }
            if(a[i]<0){
                mn=min(mn,-a[i])
            }
        }
        for(i in 0..n-1){
            if(a[i]>0 && a[i]==mn){
                s[i]=0
                break
            }
            if(a[i]<0 && a[i]==-mn){
                s[i]=1
                break
            }
        }
        println(sum-mn)
        for(i in 0..n-1) print("${s[i]}")
        println("")
    }
}