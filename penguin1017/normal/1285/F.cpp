#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define ui unsigned int
#define vi vector<ui>
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N=1e5+9;
int a[N];
struct bst{
	vi s;
	void set1(ui x){
		while(x>=s.size()*32)s.pb(0);
		s[x>>5]|=1<<(x&31);
	}
	void set0(ui x){
		while(x>=s.size()*32)s.pb(~0);
		s[x>>5]&=~(1u<<(x&31));
	}
	int get(int &pos){
		while(!s[pos])--pos;
		per(i,0,32)if(s[pos]>>i&1)return pos<<5|i;
	}
	void del1(const bst &oth){
		int c=min(s.size(),oth.s.size());
		rep(i,0,c)s[i]&=oth.s[i];
	}
	void del2(const vi &oth){
		int c=oth.size();
		rep(i,0,c){
			ui x=oth[i];
			s[x>>5]&=~(1u<<(x&31));
		} 
	}
};
bst f[50],cur;
vi g[N],p[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	cur.set1(0);
	rep(i,1,N){
		for(int j=i;j<N;j+=i)p[j].pb(i);
	}
	ll ans=a[0];
	rep(i,0,n){
		bst now=cur;
		int pos=cur.s.size()-1;
		while(1){
			int maxn=now.get(pos);
			if(!maxn)break;
			int d=__gcd(maxn,a[i]);
			ans=max(ans,1ll*maxn*a[i]/d);
			if(d<50)now.del1(f[d]);
			else now.del2(g[d]);
		}
		cur.set1(a[i]);
		for(ui v:p[a[i]]){
			if(v<50)f[v].set0(a[i]);
			else g[v].pb(a[i]);
		}
	}
	printf("%lld\n",ans);
}