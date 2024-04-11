private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrs() = readLn().split(" ")
private fun readArr() = readStrs().map({ it.toInt() })
 
var used= HashMap<Int,Int>();
//var arr = Array<Int>(100);
fun main(args: Array<String>) {
  var t=readInt();
  while(t-->0){
    var n=readInt();
    if(n<1000){
      println(n);
      continue;
    }
    if((n%1000)>=500&&n<1000000)
      n+=1000;
    n/=1000;
    if(n<1000){
      print(n);
      println("K");
      continue
    }
    if((n%1000)>=500)
      n+=1000;
    n/=1000;
    print(n);
    println("M");
  }
  /*var n=readInt();
  var arr=readArr();
  var sol=Array(n){0};
  var l=n-1;
  var i=n-1;
  while(i>=0){
    var ss=used.getOrElse(arr[i]){0};
    //println(arr[i]);
    //println(ss);
    if(ss==0)
    {
      used.put(arr[i],1);
      sol[l]=arr[i];
      l=l-1;
    }
    i--;
  }
  i=l+1;
  println(n-1-l);
  while(i<n){
    print(sol[i]);
    print(" ");
    i++;
  }*/
  //println("done");
}