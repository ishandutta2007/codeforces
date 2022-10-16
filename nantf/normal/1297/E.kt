fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b
fun maxll(a:Long,b:Long)=if(a>b) a else b
fun minll(a:Long,b:Long)=if(a<b) a else b

var el=0
var head=IntArray(300030){0}
var to=IntArray(600060){0}
var nxt=IntArray(600060){0}
var deg=IntArray(300030){0}
var stk=IntArray(300030){0}
var tp=0

fun add(u:Int,v:Int){
    el++
    to[el]=v
    nxt[el]=head[u]
    head[u]=el
}

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        var arr=readInts()
        var n=arr[0]
        var k=arr[1]
        for(i in 0..n-2){
            arr=readInts()
            var u=arr[0]-1
            var v=arr[1]-1
            deg[u]++
            deg[v]++
            add(u,v)
            add(v,u)
        }
        for(i in 0..n-1) if(deg[i]==1){
            tp++
            stk[tp]=i
        }
        if(tp<k) println("No")
        else{
            println("Yes")
            while(tp>k){
                var u=stk[tp]
                tp--
                deg[u]--
                var i=head[u]
                while(i!=0){
                    var v=to[i]
                    deg[v]=max(0,deg[v]-1)
                    if(deg[v]==1){
                        tp++
                        stk[tp]=v
                    }
                    i=nxt[i]
                }
            }
            if(tp==1) deg[stk[1]]=1
            var m=0
            for(i in 0..n-1) if(deg[i]!=0) m++
            println(m)
            for(i in 0..n-1) if(deg[i]!=0) print("${i+1} ")
            println("")
        }
        for(i in 0..n-1){
            head[i]=0
            deg[i]=0
        }
        for(i in 1..el){
            to[i]=0
            nxt[i]=0
        }
        el=0
        tp=0
    }
}