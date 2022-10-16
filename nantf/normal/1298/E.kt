fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun main(){
    var a=readInts()
    var n=a[0]
    var m=a[1]
    var r=readInts()
    var ans=Array(n){0}
    var tmp=r
    tmp=tmp.sorted().toIntArray()
    var cur=0
    for(i in 0..n-1){
        var lft=0;
        var rig=n-1
        while(lft<rig){
            var mid=(lft+rig)/2
            if(tmp[mid]<r[i]) lft=mid+1;
            else rig=mid;
        }
        ans[i]=lft
    }
    while(m!=0){
        m--
        a=readInts()
        var u=a[0]-1
        var v=a[1]-1
        if(r[u]>r[v]) ans[u]--
        if(r[v]>r[u]) ans[v]--
    }
    for(i in 0..n-1) print("${ans[i]} ")
}