#include "bits/stdc++.h"

using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int M;
		cin>>M;
		vector<int>v(7);
		int cnt=0;
		for(int j=0;j<7;j++){
			cin>>v[j];
			cnt+=v[j];
		}
		int ans=max(0,M/cnt-1);
		M-=ans*cnt;
		ans*=7;
		int add=100;
		for(int j=0;j<7;j++){
			int box=0;
			for(int k=0;k<21;k++){
				box+=v[(j+k)%7];
				if(box==M)add=min(add,k);
			}
		}
		cout<<ans+add+1<<endl;
	}
	return 0;
}