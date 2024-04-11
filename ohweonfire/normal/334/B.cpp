#include <iostream>
#include <utility>
#include <set>
using namespace std;
set<int> xz,yz;
set<pair<int,int> > xyz;
int main(){
	int x,y,i;
	for(i=0;i<9;i++){cin>>x>>y;xz.insert(x);yz.insert(y);xyz.insert(make_pair(x,y));}
	if(xz.size()==3&&yz.size()==3&&xyz.size()==8){
		int xx=*(++xz.begin()),yy=*(++yz.begin());
		if(xyz.find(make_pair(xx,yy))==xyz.end())cout<<"respectable\n";
		else cout<<"ugly\n";
	}
	else cout<<"ugly\n";
	return 0;
}