#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=100005;
vector<int> V[Maxn];
int n;
int cnt[1000005];
bool f[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int v;
		scanf("%d",&v);
		for (int j=0;j<v;j++){
			int x;
			scanf("%d",&x);
			V[i].pb(x);
		}
		bool flag=true;
		for (int j=0;j<v-1;j++){
			if (V[i][j]<V[i][j+1]){
				flag=false;
			}
		}
		f[i]=flag;
		if (flag) cnt[V[i][0]]++;
	}
	for (int i=1;i<1000005;i++) cnt[i]+=cnt[i-1];
	LL ans=0;
	for (int i=0;i<n;i++){
		if (f[i]){
			ans+=cnt[V[i].back()];
			//if (V[i][0]==V[i].back()) ans--;
		}
	}
	ans=1ll*n*(n)-ans;
	printf("%lld\n",ans);
	return 0;
}