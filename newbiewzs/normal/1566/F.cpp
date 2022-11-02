#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<cmath> 
#include<set>
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define mp make_pair
typedef long long ll;
using namespace std;
int read(){
	char c=getchar();int x=1;int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=2e5+5;
int n,m;
int a[N],l[N],r[N],L[N],R[N];
vector<pii> v[N],tmp;
int f[N][2];//  i   i  
void solve(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		l[i]=read();r[i]=read();
		int x=lower_bound(a+1,a+n+1,l[i])-a;
		if(x<=n and r[i]>=a[x])continue;
		v[x].pb(mp(l[i],r[i]));
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		for(int k=0;k<v[i].size();k++){
			int x=v[i][k].fi;
			int y=v[i][k].se;
			if(tmp.size() && tmp.back().fi==x)continue;
			while(tmp.size() and tmp.back().se>=y)tmp.pop_back();
			tmp.pb(mp(x,y));
		}
		v[i]=tmp;tmp.clear();
		if(i!=1)v[i].insert(v[i].begin(),mp(a[i-1],a[i-1]));
		v[i].insert(v[i].end(),mp(a[i],a[i]));
		sort(v[i].begin(),v[i].end());
	}
	v[n+1].pb(mp(a[n],a[n]));
	sort(v[n+1].begin(),v[n+1].end());
	memset(f,10,sizeof(f));
	f[1][0]=(a[1]-v[1][0].se);
	f[1][1]=(a[1]-v[1][0].se)*2ll;
	for(int i=2;i<=n;i++){
		for(int k=0;k+1<v[i].size();k++){
			for(int j=0;j<=1;j++){
				for(int h=0;h<=1;h++){
					f[i][j]=min(f[i][j],f[i-1][h]+(2-h)*(v[i][k].fi-a[i-1])+(1+j)*(a[i]-v[i][k+1].se));
				}
			}
		}
	}
	int ans=0;
	ans=min(f[n][0]+2ll*(v[n+1].back().fi-a[n]),f[n][1]+v[n+1].back().fi-a[n]);
	cout<<ans<<'\n';
	memset(f,0,sizeof(f));
	for(int i=1;i<=n+1;i++)v[i].clear();
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/