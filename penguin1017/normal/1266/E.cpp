#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+9;
ll a[N],b[N],ans;
map<pii,int> mp;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%lld",&a[i]),ans+=a[i];
	int q;
	scanf("%d",&q);
	while(q--){
		int s,t,u;
		scanf("%d%d%d",&s,&t,&u);
		int id=mp[{s,t}];
		if(id){
			if(b[id]>a[id])--b[id];
			else ++ans,--b[id];
			mp[{s,t}]=u;
			if(!u){
				printf("%lld\n",ans);
				continue;
			}
			if(b[u]<a[u])--ans,++b[u];
			else ++b[u];
		}
		else{
			mp[{s,t}]=u;
			if(!u){
				printf("%lld\n",ans);
				continue;
			}
			if(b[u]<a[u])--ans,++b[u];
			else ++b[u];
		}
		printf("%lld\n",ans);
	}
}