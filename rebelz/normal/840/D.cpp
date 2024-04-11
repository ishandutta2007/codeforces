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

int n,q;
int a[300005],cnt[300005];
vector<int> v[300005];
bool vis[300005];

int main(){
	mt19937 mrand(19260817);
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) v[a[i]].pb(i);
	int l,r,k;
	while(q--){
		l=readint(); r=readint(); k=readint();
		k=(r-l+1)/k;
		if(r-l+1<=300){
			for(int i=l;i<=r;i++) cnt[a[i]]++;
			int mina=n+1;
			for(int i=l;i<=r;i++){
				if(cnt[a[i]]>k) chkmin(mina,a[i]);
				cnt[a[i]]=0;
			}
			if(mina>n) printf("-1\n");
			else printf("%d\n",mina);
		}
		else{
			vector<int> gar(0);
			int mina=n+1;
			for(int i=1;i<=100;i++){
				int pl=mrand()%(r-l+1)+l;
				if(v[a[pl]].size()<=k) continue;
				if(vis[a[pl]]) continue;
				if(upper_bound(v[a[pl]].begin(),v[a[pl]].end(),r)-lower_bound(v[a[pl]].begin(),v[a[pl]].end(),l)>k) chkmin(mina,a[pl]);
				vis[a[pl]]=1;
				gar.pb(a[pl]);
			}
			if(mina>n) printf("-1\n");
			else printf("%d\n",mina);
			for(auto r:gar) vis[r]=0;
		}
	}
	return 0;
}