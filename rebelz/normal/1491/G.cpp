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
int a[200005];
bool vis[200005];
vector<pii> ans;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	vector<int> lst(0);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vector<int> v(1,i);
		vis[i]=1;
		for(int j=a[i];j!=i;j=a[j]) v.pb(j),vis[j]=1;
		if(v.size()==1) continue;
		if(lst.size()){
			ans.pb(mp(v[0],lst[0]));
			for(int j=1;j<lst.size();j++) ans.pb(mp(v[0],lst[j]));
			for(int j=1;j<v.size();j++) ans.pb(mp(lst[0],v[j]));
			ans.pb(mp(v[0],lst[0]));
			lst.clear();
		}
		else lst=v;
	}
	if(lst.size()){
		if(lst.size()==2){
			int pl=0;
			for(int i=1;i<=n;i++) if(i!=lst[0]&&i!=lst[1]) pl=i;
			ans.pb(mp(lst[0],pl));
			ans.pb(mp(pl,lst[1]));
			ans.pb(mp(lst[0],pl));
		}
		else{
			ans.pb(mp(lst[0],lst[1]));
			ans.pb(mp(lst[1],lst[2]));
			for(int i=3;i<lst.size();i++) ans.pb(mp(lst[1],lst[i]));
			ans.pb(mp(lst[0],lst[2]));
			ans.pb(mp(lst[0],lst[1]));
		}
	}
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
	return 0;
}