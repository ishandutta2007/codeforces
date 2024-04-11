import java.math.BigInteger
import java.util.*
import kotlin.math.*

fun rs()=readLine()!!
fun ri()=rs().toInt()
fun rl()=rs().toLong()
fun rd()=rs().toDouble()
fun ris()=rs().split(" ").map{it.toInt()}
fun rls()=rs().split(" ").map{it.toLong()}
fun rds()=rs().split(" ").map{it.toDouble()}

val out=mutableListOf<String>()
fun pln(s:String){out.add(s)}
fun pln(i:Int)=pln(i.toString())
fun pln(l:Long)=pln(l.toString())
fun pln(d:Double,precision:Int=12)=pln(("%."+precision.toString()+"f").format(d))
fun pln(a:IntArray)=pln(a.joinToString(" "))
fun pln(a:LongArray)=pln(a.joinToString(" "))
fun<T> pln(a:Array<T>)=pln(a.joinToString(" "))
fun<T> pln(a:ArrayList<T>)=pln(a.joinToString(" "))
fun output(){println(out.joinToString("\n"))}

fun main(){
    var(n,d)=ris()
    var a=ris()
    var ost=Array(10){ArrayList<Int>()}
    for(i in a){
        ost[i%10].add(i)
    }
    for(i in 0 until 10){
        ost[i].sort()
    }
    var ans=ArrayList<Int>()
    if(d==0){
        var x=1
        for(i in a){
            ans.add(i)
            x=(x*i)%10
        }
        if(x==0){
            pln(ans.size)
            pln(ans)
        }else{
            pln(-1)
        }
    }else if(d==5){
        var x=1
        for(i in 1 until 10 step 2){
            for(j in ost[i]){
                x=(x*j)%10
                ans.add(j)
            }
        }
        if(x==5){
            pln(ans.size)
            pln(ans)
        }else{
            pln(-1)
        }
    }else{
        if(d%2==1){
            for(i in 0 until 10 step 2)ost[i].clear()
        }
        var mx=1*4*4*2*1*4*4*2
        var num=arrayOf(1,2,3,4,6,7,8,9)
        var dv=arrayOf(1,4,4,2,1,4,4,2)
        var mn=BigInteger("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
        var best=mx
        for(mask in 0 until mx){
            var tmp=mask
            var ok=true
            var other=BigInteger("1")
            var x=1
            for(i in 0 until 8){
                var take=tmp%dv[i]
                if(take>ost[num[i]].size){
                    ok=false
                    break
                }
                var t=(ost[num[i]].size-take)
                if(t>0){
                    t=t%4
                    if(t==0)t=4
                }
                for(j in 0 until t){
                    x=x*num[i]%10
                }
                for(j in 0 until take){
                    other=other.multiply(BigInteger.valueOf(ost[num[i]][j].toLong()))
                }
                tmp/=dv[i]
            }
            if(ok&&x==d){
                if(mn>other){
                    mn=other
                    best=mask
                }
            }
        }
        if(best==mx){
            pln(-1)
        }else{
            var tmp=best
            for(i in 0 until 8){
                var take=tmp%dv[i]
                for(j in take until ost[num[i]].size){
                    ans.add(ost[num[i]][j])
                }
                tmp/=dv[i]
            }
            if(ans.size==0){
                pln(-1)
            }else{
                pln(ans.size)
                pln(ans)
            }
        }
    }
    output()
}