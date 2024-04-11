fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun maxll(a:Long,b:Long)=if(a>b) a else b
fun minll(a:Long,b:Long)=if(a<b) a else b

var n=0
var a=IntArray(2020){0}
var b=IntArray(2020){0}

fun check(x:Int):Boolean{
    var cnt=0
    for(i in 0..n-1) if(x in a[i]..b[i]) cnt++
    return cnt==1
}

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        n=readInt()
        var arr=IntArray(n){2}
        for(i in 0..n-1){
            arr=readInts()
            a[i]=arr[0]
            b[i]=arr[1]
        }
        var flag=false
        for(i in 0..n-1){
            if(check(a[i]-1)){
                println(a[i]-1)
                flag=true
                break
            }
            if(check(a[i])){
                println(a[i])
                flag=true
                break
            }
            if(check(a[i]+1)){
                println(a[i]+1)
                flag=true
                break
            }
            if(check(b[i]-1)){
                println(b[i]-1)
                flag=true
                break
            }
            if(check(b[i])){
                println(b[i])
                flag=true
                break
            }
            if(check(b[i]+1)){
                println(b[i]+1)
                flag=true
                break
            }
        }
        if(flag==false) println(-1)
    }
}