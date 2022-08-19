// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int f[2005],lf[2005],rg[2005];
char s[2005][2005];
vector<pii> vec;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+i);
		vec.clear();
		for(int i=2;i<=n;i++)
			for(int j=1;j+i-1<=n;j++)
				if(s[j][j+i-1]=='1') vec.pb(mp(j,j+i-1));
		for(int i=1;i<=n;i++) f[i]=i,lf[i]=rg[i]=i;
		vector<pii> ans(0);
		for(auto i:vec){
			int l=i.fi,r=i.se;
			int fx=getf(l),fy=getf(r);
			if(fx==fy) continue;
//			cout<<"test "<<l<<' '<<r<<endl;
			vector<int> th(0);
			for(int j=fx;j!=fy;j=getf(j+1)) th.pb(j);
			th.pb(fy);
			vector<int> tmp(0);
			if(th.size()&1){
				tmp.pb(max(l,lf[th[2]]));
				tmp.pb(max(l,lf[th[0]]));
				for(int j=4;j<th.size();j+=2) tmp.pb(min(r,rg[th[j]]));
				for(int j=1;j<th.size();j+=2) tmp.pb(min(r,rg[th[j]]));
			}
			else{
				for(int j=1;j<th.size();j+=2) tmp.pb(min(r,rg[th[j]]));
				for(int j=0;j<th.size();j+=2) tmp.pb(max(l,lf[th[j]]));
			}
			for(int j=1;j<tmp.size();j++) ans.pb(mp(tmp[j-1],tmp[j]));
			for(int j=0;j<th.size()-1;j++) f[th[j]]=fy;
			lf[fy]=lf[th[0]];
		}
		for(auto r:ans) printf("%d %d\n",r.fi,r.se);
	}
	return 0;
}