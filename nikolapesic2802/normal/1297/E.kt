private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrs() = readLn().split(" ")
private fun readArr() = readStrs().map({ it.toInt() })
 
var used= HashMap<Int,Int>();
//var arr = Array<Int>(100);
fun main(args: Array<String>) {
  var t=readInt();
  while(t-->0){
    var (n,k)=readArr();
    var done = Array(n+1){0};
    done[n]=1;
    var g=Array(n){mutableListOf(n)};
    var deg=Array(n){0};
    var q=Array(n){0};
    var frnt=0;
    var bck=0;
    for(i in 1..n-1){
      var (a,b)=readArr();
      a--;
      b--;
      g[a].add(b);
      g[b].add(a);
      deg[a]++;
      deg[b]++;
      //println("$a $b");
    }
    //var q=mutableListOf(n);
    //q.removeAt(0);
    var tr=0;
    for(i in 0..n-1){
      //println("$i       ${deg[i]}");
      if(deg[i]==1){
        q[bck++]=i;
        tr++;
       }
    }
    if(tr<k){
      println("No");
      continue;
    }
    while(tr>k)
    {
      var a=q[frnt++];
      done[a]=1;
      tr--;
      //println("$a  $tr");
      //q.removeAt(0);
      for(t in g[a]){
        if(done[t]==0){
          deg[t]--;
          if(deg[t]==1){
            q[bck++]=t;
            tr++;
          }
        }
      }
    }
    println("Yes");
    var sol=mutableListOf(0);
    sol.removeAt(0);
    for(i in 0..n-1){
      if(done[i]==0)
        sol.add(i);
    }
    println(sol.count());
    for(t in sol){
      print("${t+1} ");
    }
    println();
  }
  //print("done");
  /*var t=readInt();
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
  }*/
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