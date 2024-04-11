private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrs() = readLn().split(" ")
private fun readArr() = readStrs().map({ it.toInt() })
 
//var used= HashMap<Int,Int>();
//var arr = Array<Int>(100);
class CustomComparator : Comparator<Pair<Int, Pair<Int, Int>>> {
    override fun compare(o1: Pair<Int, Pair<Int, Int>>, o2: Pair<Int, Pair<Int, Int>>): Int {
        return o1.first.compareTo(o2.first)
    }
}

class CustomComparator2 : Comparator<Pair<Int, Int>> {
    override fun compare(o1: Pair<Int, Int>, o2: Pair<Int, Int>): Int {
        return o1.first.compareTo(o2.first)
    }
}

fun main(args: Array<String>) {
  var t=readInt();
  while(t-->0){
	var n = readInt();
	var arrayList = ArrayList<Pair<Int,Int> >();
	for(i in 0..n-1){
		var (a,b)=readArr();
		arrayList.add(Pair<Int,Int>(a,1));
		arrayList.add(Pair<Int,Int>(b+1,-1));
	}
	arrayList.sortWith(CustomComparator2());
	var cnt=0;
	var ok=arrayList.count();
	var nasao=-1;
	for(i in 0..ok-1){
		cnt+=arrayList[i].second;
		if(i==ok-1||arrayList[i+1].first!=arrayList[i].first){
			if(cnt==1){
				nasao=arrayList[i].first;
				break;
			}
		}
	}
	println(nasao);
  }
  //print("DONE");
}