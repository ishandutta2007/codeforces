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
        var a=readInts()
        var n=a[0]
        var k=a[1]
        a=readInts()
        var id=IntArray(n){0}
        var d=IntArray(n){0}
        for(i in 0..n-1) id[i]=i
        id=id.sortedBy{a[it]}.toIntArray()
        var lft=a[id[n-1]]
        var rig=a[id[n-1]]+k;
        while(lft<rig){
            var mid=((lft.toLong()+rig.toLong())/2).toInt()
            var tmp=k
            var flag=true
            for(ii in n-1 downTo 0){
                var i=id[ii]
                var x=mid-(n-1-ii)-a[i]
                if(x<0) flag=false
                else{
                    d[i]=min(x,tmp)
                    tmp-=d[i]
                }
            }
            if(tmp==0 && flag) rig=mid
            else lft=mid+1
        }
        var mid=lft
        var tmp=k
        var flag=true
        for(ii in n-1 downTo 0){
            var i=id[ii]
            var x=mid-(n-1-ii)-a[i]
            if(x<0) flag=false
            else{
                d[i]=min(x,k)
                k-=d[i]
            }
        }
        for(i in 0..n-1) print("${d[i]} ")
        println("")
    }
}