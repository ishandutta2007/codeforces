fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

var m=0
var b=IntArray(300030){0}
var n=0
var cur=0
var pre=IntArray(300030){0}
var nxt=IntArray(300030){0}
var cnt=IntArray(300030){0}
var id=IntArray(300030){0}
var to=IntArray(300030){0}
var at=IntArray(300030){-1}

fun remove(a:Int){
    var x=pre[a]
    var y=nxt[a]
    nxt[x]=y
    pre[y]=x
}

fun main(){
    m=readInt()
    b=readInts()
    for(i in 0..m-1) if(b[i]==-1) n++
    for(i in 0..n-1){
        if(i==0) pre[i]=n-1
        else pre[i]=i-1
        if(i==n-1) nxt[i]=0
        else nxt[i]=i+1
    }
    for(i in 0..m-1){
        if(b[i]==-1) remove(cur)
        else{
            cnt[cur]++
            id[i]=cur
        }
        cur=nxt[cur]
    }
    for(i in m-1 downTo 0){
        if(b[i]!=-1){
            to[i]=at[id[i]]
            at[id[i]]=i
        }
    }
    println(n)
    for(i in 0..n-1){
        print("${cnt[i]} ")
        if(cnt[i]!=0){
            var x=at[i]
            while(x!=-1){
                print("${b[x]} ")
                x=to[x]
            }
        }
        println("")
    }
}