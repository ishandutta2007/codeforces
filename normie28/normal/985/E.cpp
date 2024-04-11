#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (ll(1000000007))
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
ll n,k,i,j,lu,lv,t,t1,dp[1000001],al,ah,aw,dl,dh,dw,bl,bh,bw,cl,ch,cw,peri=0,res=1;
vector<ll> pens;
struct segment_tree{
    int seg[4 * 500001];
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int i, int val){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            seg[id] = max(seg[id],val);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = max( seg[id << 1] , seg[id << 1 | 1]);
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1,aa=get(id << 1, l, mid, u, v),bb=get(id << 1 | 1, mid + 1, r, u, v);
        return max( aa,bb);
    }
} it1;
int main()
{
	cin>>n>>k>>t;
	for (i=1;i<=n;i++)
	{
		cin>>lu;
		pens.push_back(lu);
	}
	sort(pens.begin(),pens.end());
	dp[0]=1;
	j=0;
		it1.update(1,0,n,0,dp[0]);
	for (i=1;i<=n;i++)
	{
		while(pens[i-1]-pens[j]>t) j++;
		dp[i]=it1.get(1,0,n,j,i-k);
		it1.update(1,0,n,i,dp[i]);
	}
	if (dp[n]) cout<<"YES"; else cout<<"NO";
}