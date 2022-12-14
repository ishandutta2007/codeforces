#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;
 
int n;
int main(){
	cin>>n;
	set<pair<int,int> > s;
	for(int i=0;i<=n;i++){
		s.insert(make_pair(i,i));
		s.insert(make_pair(i+1,i));
		s.insert(make_pair(i,i+1));
		s.insert(make_pair(i+1,i+1));
	}
	cout<<s.size()<<endl;
	for(auto el:s){
		printf("%d %d \n",el.first+1,el.second+1);
	}
	return 0;
}