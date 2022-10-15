/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
// thanks, bachan
struct max_lazy_segment_tree{
    int seg[4 * 1000000], lazy[4 * 1000000];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] ;
        seg[id << 1 | 1] += lazy[id] ;
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return max(get(id << 1, l, mid, u, v) , get(id << 1 | 1, mid + 1, r, u, v));
    }
} maxst;
struct min_lazy_segment_tree{
    int seg[4 * 1000000+1], lazy[4 * 1000000+1];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] ;
        seg[id << 1 | 1] += lazy[id] ;
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = min(seg[id << 1] , seg[id << 1 | 1]);
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = min(seg[id << 1] , seg[id << 1 | 1]);
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v) , get(id << 1 | 1, mid + 1, r, u, v));
    }
} minst;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j,sum;
int val[1000000];
int get_val (char c)
{
	if (c=='(') return 1;
	if (c==')') return -1;
	return 0;
}
int main()
{
//  ofile;
    fio;
    minst.build(1,0,1e6-1);
    maxst.build(1,0,1e6-1);
    cin>>n;
    for (i=0;i<n;i++)
    {
    	char c;
    	cin>>c;
    	if (c=='R') j++;
    	else if (c=='L') {j--; if (j<0) j++;}
    	else 
    	{
    		k=get_val(c)-val[j];
    		sum+=k;
    		minst.update(1,0,1e6-1,j,1e6-1,k);
    		maxst.update(1,0,1e6-1,j,1e6-1,k);
    		val[j]=get_val(c);
    	}
    	if ((sum==0)and(minst.get(1,0,1e6-1,0,1e6-1)>=0))
    	cout<<maxst.get(1,0,1e6-1,0,1e6-1)<<' ';
    	else cout<<-1<<' ';
    }
}