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
ll a[10],b[100005],pl[100005];
set<pii> s;

int main(){
	for(int i=1;i<=6;i++) a[i]=readint();
	sort(a+1,a+7);
	n=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) pl[i]=6;
	for(int i=1;i<=n;i++) s.insert(mp(b[i]-a[6],i));
	int ans=(--s.end())->fi-s.begin()->fi;
	while(1){
		auto it=s.begin();
		if(pl[it->se]==1) break;
		int id=it->se; s.erase(it);
		pl[id]--;
		s.insert(mp(b[id]-a[pl[id]],id));
		chkmin(ans,(--s.end())->fi-s.begin()->fi);
	}
	printf("%d\n",ans);
	return 0;
}