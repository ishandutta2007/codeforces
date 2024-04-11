/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char c[200005],s[200005];
int it[26],n;
bool f[200005];
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p){
			s[p]+=x;
			p-=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p<=n){
			re=re+s[p];
			p+=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		f[i]=1;
		cin>>c[i];s[i]=c[i];
	}
	reverse(s+1,s+n+1);
	FILL(it,0);
	int ans=0;
	FOR(i,1,n){
		int now=s[i]-'a';
		gmax(it[now],1ll);
		while(1){
			if(f[it[now]]&&c[it[now]]==s[i]){
				f[it[now]]=0;break;
			}
			it[now]++;
		}
		ans+=max(it[now]+tree.get(it[now])-i,0ll);
		tree.up(it[now],1);
//		cout<<ans<<'\n';
	}
	cout<<ans;
	RE 0;
}