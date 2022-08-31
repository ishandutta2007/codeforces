#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[300005],ans[300005];
vector<int> v[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) v[a[i]].pb(i);
		for(int i=1;i<=n;i++) ans[i]=n+1;
		for(int i=1;i<=n;i++){
			int lst=0,d=0;
			for(auto r:v[i]){
				chkmax(d,r-lst);
				lst=r;
			}
			chkmax(d,n+1-lst);
			chkmin(ans[d],i);
		}
		for(int i=1;i<=n;i++) chkmin(ans[i+1],ans[i]);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]==n+1?-1:ans[i]);
		printf("\n");
	}
	return 0;
}