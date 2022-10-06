#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>

using namespace std; 


int main(){

	int n;
	cin>>n;

	vector<pair<long long,long long> > seg(n);
	for(int i=0;i<n;i++){
		long long x,w;
		cin>>x>>w;
		seg[i]=make_pair(x+w,x-w);
	}

	sort(seg.begin(),seg.end());
	
	int res=1;
	long long now=seg[0].first;
	for(int i=1;i<n;i++){
		if(now<=seg[i].second){
			res++;
			now=seg[i].first;
		}
	}

	cout<<res<<endl;


	return 0;

}