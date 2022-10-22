#include "bits/stdc++.h"
using namespace std;

void Solve(){
	int N;
	cin>>N;
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	vector<int>ans(N);
	int num=accumulate(v.begin(),v.end(),0LL)/N;
	int amari=num;
	deque<int>zero;
	for(int i=0;i<amari;i++){
	    zero.push_back(N);
	}
	for(int i=N-1;i>=0;i--){
	    int fst=-1;
	    if(amari>0&&zero.size()>=amari){
	        fst=zero[amari-1];
	    }
	    if(fst==v[i]){
	        ans[i]=1;
	        amari--;
	    }
	    else{
	        zero.push_front(i);
	    }
	}
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	
	return 0;
}