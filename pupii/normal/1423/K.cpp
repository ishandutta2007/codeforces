#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int sum[N];
bool vis[N];

void add(int l,long long r) {
	++sum[l];
	if(r+1<N) --sum[r+1];
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	for(int i=2;i<N;i++)
		if(!vis[i])
			for(int j=i+i;j<N;j+=i) vis[j]=1;
	add(1,1e9);
	for(int i=2;i<N;i++)
		if(!vis[i]) add(i,1ll*i*i-1);
	for(int i=1;i<N;i++) sum[i]+=sum[i-1];
	int T;cin>>T;
	while(T--) {
		int n;cin>>n;
		cout<<sum[n]<<'\n';
	}
	return 0;
}