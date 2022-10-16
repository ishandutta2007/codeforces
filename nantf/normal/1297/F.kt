fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun maxll(a:Long,b:Long)=if(a>b) a else b
fun minll(a:Long,b:Long)=if(a<b) a else b

var sz=0
var a=IntArray(200020){0}
var r=IntArray(200020){0}

fun push(x:Int){
    sz++
    a[sz]=x
    var now=sz
    while(now>1){
        var fa=now/2
        if(r[a[now]]<r[a[fa]]){
            var tmp=a[now]
            a[now]=a[fa]
            a[fa]=tmp
        }
        else break
        now=fa
    }
}

fun pop(){
    a[1]=a[sz]
    sz--
    var now=1
    while(now*2<=sz){
        var son=now*2
        if(son<sz && r[a[son+1]]<r[a[son]]) son++
        if(r[a[now]]>r[a[son]]){
            var tmp=a[now]
            a[now]=a[son]
            a[son]=tmp
        }
        now=son
    }
}

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        var arr=readInts()
        var n=arr[0]
        var m=arr[1]
        var l=IntArray(n){0}
        var ans=0
        var s=IntArray(n){0}
        for(i in 0..n-1){
            arr=readInts()
            l[i]=arr[0]
            r[i]=arr[1]
        }
        var id=IntArray(n){0}
        for(i in 0..n-1) id[i]=i
        id=id.sortedBy{l[it]}.toIntArray()
        var i=0
        var curt=0
        while(i<n){
            var j=i
            while(j<n && l[id[i]]==l[id[j]]) j++
            j--
            curt=l[id[i]]
            for(k in i..j) push(id[k])
            while(sz!=0 && (j==n-1 || curt<l[id[j+1]])){
                var tmp=min(sz,m)
                while(tmp!=0){
                    tmp--
                    var x=a[1]
                    ans=max(ans,curt-r[x])
                    s[x]=curt
                    pop()
                }
                curt++
            }
            i=j+1
        }
        println(ans)
        for(i in 0..n-1) print("${s[i]} ")
        println("")
    }
}