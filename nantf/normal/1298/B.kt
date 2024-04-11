fun readInt()=readLine()!!.toInt()
fun readInts()=readLine()!!.split(" ").map(String::toInt)
fun main(){
    var n=readInt()
    var a=readInts()
    var m=0
    var b=IntArray(55){0}
    var c=BooleanArray(1111){false}
    for(i in n-1 downTo 0){
        if(!c[a[i]]){
            c[a[i]]=true
            b[m]=a[i]
            m++
        }
    }
    println(m)
    for(i in m-1 downTo 0) print("${b[i]} ")
}