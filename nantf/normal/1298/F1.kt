fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

var bit=IntArray(400040){0}
var n=0
var m=0

fun update(p:Int,v:Int){
    var i=p
    while(i<=2*n+1){
        bit[i]+=v
        i+=i and -i
    }
}

fun query(p:Int):Int{
    var s=0
    var i=p
    while(i!=0){
        s+=bit[i]
        i-=i and -i
    }
    return s
}

var a=IntArray(200020){0}

fun calc(m:Int):Long{
    var b=IntArray(n){0}
    for(i in 0..n-1){
        if(a[i]<=m) b[i]=1;
        else b[i]=-1;
    }
    var s=IntArray(n){0}
    s[0]=b[0]
    for(i in 1..n-1) s[i]=s[i-1]+b[i]
    var ans=0L
    update(n+1,1)
    for(i in 0..n-1){
        ans+=query(s[i]+n+1)
        update(s[i]+n+1,1)
    }
    update(n+1,-1)
    for(i in 0..n-1) update(s[i]+n+1,-1)
    return ans
}

fun main(){
    a=readInts()
    n=a[0]
    m=a[1]
    a=readInts()
    println(calc(m)-calc(m-1))
}