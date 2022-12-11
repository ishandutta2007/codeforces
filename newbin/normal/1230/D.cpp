#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 7e3 + 50;
int n;
struct node{
    ll a,b;
    bool operator < (const node& x) const{return a < x.a;}
}e[maxn];
int vis[maxn];
int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i){
        cin>>e[i].a;
	}
	for(int i = 1; i <= n; ++i) cin>>e[i].b;
	sort(e+1,e+1+n);
	ll ans = 0;
	for(int i = 2; i <= n; ++i){
        if(e[i].a != e[i-1].a) continue;
        for(int j = 1; j <= i; ++j){
            if((e[j].a & e[i].a) == e[j].a) vis[j] = 1;
        }
	}
	for(int i = 1; i <= n; ++i) if(vis[i]) ans += e[i].b;
	cout<<ans<<endl;
}