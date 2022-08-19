#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

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
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) a[i]=readint(),v[a[i]].pb(i);
		for(int i=1;i<=n;i++) ans[i]=0;
		int l=1,r=n;
		for(int i=1;i<=n;i++){
			if(!v[i].size()) break;
			ans[n-i+1]=1;
			if(a[l]!=i&&a[r]!=i) break;
			else if(a[l]==i){
				if(v[i].size()==1) l++;
				else break;
			}
			else if(a[r]==i){
				if(v[i].size()==1) r--;
				else break;
			}
			else break;
		}
		bool fl=1;
		for(int i=1;i<=n;i++) if(v[i].size()!=1) fl=0;
		ans[1]=fl;
		for(int i=1;i<=n;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}