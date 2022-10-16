private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrs() = readLn().split(" ")
private fun readArr() = readStrs().map({ it.toInt() })
 

fun main(args: Array<String>) {
  var (a,b,c,d)=readArr();
  var o=listOf(a,b,c,d).max()!!.toInt();
  a-=o;
  b-=o;
  c-=o;
  d-=o;
  if(a!=0){
    print(-a);
    print(" ");
  }
  if(b!=0){
    print(-b);
    print(" ");
  }
  if(c!=0){
    print(-c);
    print(" ");
  }
  if(d!=0){
    print(-d);
    print(" ");
  }
}