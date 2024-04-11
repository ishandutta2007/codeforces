object SCALAMAIN extends App {
  val sc = new java.util.Scanner(System.in);
  val l: Long = sc.nextLong();
  val r: Long = sc.nextLong();
  var a : Long = 0;
  var ans : Long = 0;
  for(a <- 0 to 30) {
    var b  : Long= 0;
    for(b <- 0 to 19) {
      var cur : Long = 1;
      { var c : Long = 0; for(c <- 1 to a) cur *= 2; }
      { var c : Long = 0; for(c <- 1 to b) cur *= 3; }
      if(l <= cur && cur <= r) {
        ans += 1;
      }
    }
  }
  println("" + ans);
}