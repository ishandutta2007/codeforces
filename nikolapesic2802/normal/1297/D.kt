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
	var (n,k)=readArr();
	var a = readArr();
	var arrayList = ArrayList<Pair<Int,Int> >();
	for(i in 0..n-1)
		arrayList.add(Pair<Int,Int>(a[i],i));
	arrayList.sortWith(CustomComparator2());
	var add = Array<Int>(n){0};
	var samo = Array<Int>(n){0};
	for(i in 0..n-2){
		var d=arrayList[i+1].first-arrayList[i].first-1;
		var o=i+1;
		var koliko=k/o;
		var ostalo=k%o;
		if(koliko>=d)
			ostalo=0;
		if(koliko>d)
			koliko=d;
		//println("$i  $koliko $ostalo $k");
		add[i]=koliko;
		k-=koliko*o+ostalo;
		samo[i]=ostalo;
	}
	add[n-1]=k/n;
	samo[n-1]=k%n;
	var sol = Array<Long>(n){0};
	var tr:Long = 0;
	var i=n-1;
	while(i>=0){
		//println("$i  ${samo[i]}  ${add[i]}");
		tr+=add[i];
		sol[arrayList[i].second]+=tr;
		var koraka=samo[i];
		var j=i;
		while(j>=0){
			if(koraka==0)
				break;
			sol[arrayList[j].second]++;
			koraka--;
			j--;
		}
		i--;
	}
	for(i in 0..n-1)
		print("${sol[i]} ");
	println();
	/*var arrayList = ArrayList<Pair<Int,Int> >();
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
	println(nasao);*/
  }
  //print("DONE");
}