fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

var n=0
var m=0
var q=0
var a=IntArray(200020){0}
var s=IntArray(200020){0}
var x=IntArray(200020){0}

fun main(){
    var arr=readInts()
    n=arr[0]
    m=arr[1]
    a=readInts()
    s[0]=a[0]
    for(i in 1..n-1) s[i]=s[i-1]+a[i]
    q=readInt()
    while(q!=0){
        q--
        arr=readInts()
        var c=arr[0]
        x[0]=arr[1]-1
        for(i in 1..c-1) x[i]=arr[i+1]-arr[i]-1
        x[c]=m-arr[c]
        var cur=0
        for(i in 0..c){
            var lft=cur-1
            var rig=n-1
            while(lft<rig){
                var mid=(lft+rig+1)/2
                var tmp=s[mid]
                if(cur!=0) tmp-=s[cur-1]
                if(tmp<=x[i]) lft=mid
                else rig=mid-1;
            }
            cur=lft+1
        }
        if(cur==n) println("YES")
        else println("NO")
    }
}