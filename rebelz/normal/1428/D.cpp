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
int a[100005],lab[100005];
vector<int> v1,v2,v3,v;
vector<pii> ans;
bool vis[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) if(a[i]==1) v1.pb(i);
	for(int i=1;i<=n;i++) if(a[i]==2) v2.pb(i);
	for(int i=1;i<=n;i++) if(a[i]==3) v3.pb(i);
	for(int i=1;i<=n;i++) if(a[i]==1||a[i]==2) v.pb(i);
	int pl=0,now=0;
	for(auto r:v2){
		if(pl==v1.size()) return printf("-1\n"),0;
		while(v1[pl]<r){
			pl++;
			if(pl==v1.size()) return printf("-1\n"),0;
		}
		vis[v1[pl]]=1;
		now++;
		ans.pb(mp(r,now));
		ans.pb(mp(v1[pl],now));
		lab[r]=now;
		pl++;
	}
	if(v3.size()){
		auto it=lower_bound(v.begin(),v.end(),v3.back());
		while(it!=v.end()&&vis[*it]) it++;
		if(it==v.end()) return printf("-1\n"),0;
		int pl=*it;
		if(a[pl]==1){
			vis[pl]=1;
			now++;
			ans.pb(mp(v3.back(),now+1));
			ans.pb(mp(pl,now+1));
			ans.pb(mp(pl,now));
			now++;
		}
		else{
			vis[pl]=1;
			now++;
			ans.pb(mp(v3.back(),now));
			ans.pb(mp(pl,now));
		}
		for(int i=v3.size()-1;i>=1;i--){
			now++;
			ans.pb(mp(v3[i-1],now));
			ans.pb(mp(v3[i],now));
		}
	}
	for(int i=0;i<v1.size();i++){
		if(!vis[v1[i]]){
			now++;
			ans.pb(mp(v1[i],now));
		}
	}
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d %d\n",n-r.se+1,r.fi);
	return 0;
}