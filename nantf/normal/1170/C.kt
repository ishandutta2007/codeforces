fun readInt()=readLine()!!.toInt()
fun readInts()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun max(a:Int,b:Int)=if(a>b) a else b
fun min(a:Int,b:Int)=if(a<b) a else b

fun main(){
    var t=readInt()
    while(t!=0){
        t--
        var s1=readLine()!!
        var s2=readLine()!!
        var n=s1.length
        var m=s2.length
        if(n<m) println("NO")
        else{
            var flag=true
            var cur=0
            for(i in 0..m-1){
                if(cur>=n){
                    flag=false
                    break
                }
                if(s2[i]=='-'){
                    if(s1[cur]=='+'){
                        flag=false
                        break
                    }
                    cur++
                }
                else{
                    if(s1[cur]=='+') cur++
                    else{
                        cur++;
                        if(cur>=n || s1[cur]!='-'){
                            flag=false
                            break
                        }
                        cur++
                    }
                }
            }
            if(flag && cur==n) println("YES")
            else println("NO")
        }
    }
}