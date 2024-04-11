#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define vi vector<int> 
#define pb push_back
using namespace std;
const int N=5e5+9;
int vis[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,m;
		scanf("%d%d%d",&n,&k,&m);
		rep(i,1,n+1)vis[i]=1;
		rep(i,0,m){
			int x;
			scanf("%d",&x);
			vis[x]=0;
		}
		int len=n-m;
		if(len%(k-1)){
			puts("NO");
			continue; 
		}
		int ok=0;
		int L=1,sum=k-1>>1;
		for(;sum;++L){
			if(vis[L])--sum;
		}
		int R=n;
		sum=k-1>>1;
		for(;sum;--R){
			if(vis[R])--sum;
		} 
		++R;
		rep(i,L,R)if(!vis[i])ok=1;
		if(ok)puts("YES");
		else puts("NO");
	}
}