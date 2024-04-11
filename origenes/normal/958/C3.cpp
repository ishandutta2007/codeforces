#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=512346;
const int maxk=123;
int s[maxn], C[maxk<<1][maxk<<1], n, k, p;
inline int lowbit(int x){
	return x&-x;
}
void update(int idx, int d, int v){
	for(int i=d; i<=maxk; i+=lowbit(i))
		C[idx][i]=min(C[idx][i], v);
}
int query(int idx, int d){
	int ret=inf;
	for(int i=d; i>0; i-=lowbit(i))
		ret=min(ret, C[idx][i]);
	return ret;
}
int main(){
	cin>>n>>k>>p;
	for(int i=1; i<=n; i++){
		int u;
		cin>>u;
		s[i]=(s[i-1]+u)%p;
	}
	memset(C, 0x3f, sizeof(C));
	update(0, 1, 0);
	int ans;
	for(int i=1; i<=n; i++){
		for(int j=k; j>=1; j--){
			int mmin=min(query(j-1, s[i]+1), query(j-1, maxk)+p);
			update(j, s[i]+1, mmin);
			if(i==n&&j==k) ans=mmin;
		}
	}
	cout<<s[n]+ans<<endl;
	return 0;
}