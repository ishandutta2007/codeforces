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
	var v = readArr();
	var mx=0;
	var mn=10000;
	var ma=-10000;
	var taken = Array(n){0};
	for(i in 0..n-1){
		if(v[i]>=0){
			mx+=v[i];
			if(v[i]>0&&v[i]<mn)
				mn=v[i];
			taken[i]=1;
		}
		else{
			if(ma<v[i])
				ma=v[i];
		}
	}
	if(mn<=-ma){
		for(i in 0..n-1){
			if(v[i]==mn){
				taken[i]=0;
				break;
			}
		}
		mx-=mn;
	}
	else{
		mx+=ma;
		for(i in 0..n-1){
			if(v[i]==ma){
				taken[i]=1;
				break;
			}
		}
	}
	println(mx);
	for(i in 0..n-1)
		print(taken[i]);
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