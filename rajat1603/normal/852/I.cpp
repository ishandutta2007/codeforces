//satyaki3794
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define MOD (1000000007LL)
using namespace std;
 
typedef long long ll;
 
 
int n, ticks, val[100005], depth[100005], par[20][100005], lo[100005], hi[100005], arr[200005];
vector<int> adj[100005];
 
struct Query{
    int l, r, idx, lca;
    Query(){}
    Query(int l, int r, int idx, int lca){
        this->l = l;
        this->r = r;
        this->idx = idx;
        this->lca = lca;
    }
};
 
int q, present[100005], gender[100005];
ll temp[3], ans[200005], cnt[100005][3];
Query qarr[100005];
int BLOCK;
map<int, int> compress;
 
inline int block(int pos){
    return (pos-1)/BLOCK;
}
 
bool comp(Query a, Query b){
    int b1 = block(a.l), b2 = block(b.l);
    if(b1 != b2)    return b1 < b2;
    return a.r < b.r;
}
 
inline void update(int pos){
	for(int avoid=0;avoid<3;avoid++){
	    int v = arr[pos];
	    int value = val[v];
	    if(gender[v] == avoid)	continue;
	    if(present[v]){
	        temp[avoid] -= cnt[value][avoid]*(cnt[value][avoid]-1)/2;
	        cnt[value][avoid]--;
	        temp[avoid] += cnt[value][avoid]*(cnt[value][avoid]-1)/2;
	    }
	    else{
	        temp[avoid] -= cnt[value][avoid]*(cnt[value][avoid]-1)/2;
	        cnt[value][avoid]++;
	        temp[avoid] += cnt[value][avoid]*(cnt[value][avoid]-1)/2;
	    }	
	}
	present[arr[pos]] ^= 1;
}
 
 
 
void dfs(int v, int p, int d){
    par[0][v] = p;
    depth[v] = d;
    arr[++ticks] = v;
    lo[v] = ticks;
    for(int i=0;i<(int)adj[v].size();i++){
        int vv = adj[v][i];
        if(vv != p)
            dfs(vv, v, d+1);
    }
    arr[++ticks] = v;
    hi[v] = ticks;
}
 
int LCA(int a, int b){
 
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=0;i<20;i++)
        if((diff>>i) & 1)
            a = par[i][a];
 
    if(a == b)  return a;
 
    for(int i=19;i>=0;i--)
        if(par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    if(a == b)  return a;
    return par[0][a];
}
 
int main()
{
    // ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
 
    scanf("%d", &n);
    BLOCK = ceil(sqrt(2*n));
    BLOCK = 1000;
    for(int i=1;i<=n;i++)
    	scanf("%d", &gender[i]);

    for(int i=1;i<=n;i++){
        scanf("%d", &val[i]);
        compress[val[i]];
    }
    int cc = 0;
    for(map<int,int>::iterator it=compress.begin();it!=compress.end();it++)
        it->ss = ++cc;
    for(int i=1;i<=n;i++)
        val[i] = compress[val[i]];
 
    int e = n-1;
    while(e--){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    memset(par, -1, sizeof(par));
    dfs(1, -1, 0);
    for(int j=0;j<19;j++)
        for(int i=1;i<=n;i++)
            if(par[j][i] != -1)
                par[j+1][i] = par[j][par[j][i]];
 
// for(int i=1;i<=n;i++)   cout<<val[i]<<" ";cout<<endl;
// for(int i=1;i<=n;i++)   cout<<lo[i]<<" ";cout<<endl;
// for(int i=1;i<=n;i++)   cout<<hi[i]<<" ";cout<<endl;
// for(int i=1;i<=ticks;i++)   cout<<arr[i]<<" ";cout<<endl;
 
 	scanf("%d", &q);
// q=1;
    for(int i=0;i<q;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        int lca = LCA(a, b);
        if(depth[a] > depth[b]) swap(a, b);
        if(lca == a){
            qarr[i].l = lo[a];
            qarr[i].r = lo[b];
            qarr[i].idx = i;
            qarr[i].lca = lca;
        }
        else{
            if(lo[b] < lo[a]) swap(a, b);
            qarr[i].l = hi[a];
            qarr[i].r = lo[b];
            qarr[i].idx = i;
            qarr[i].lca = lca;
        }
    }
 
    sort(qarr, qarr+q, comp);
 // q=1;
    int curr_lo = 1, curr_hi = 1;
    update(1);
    for(int i=0;i<q;i++){
 
        int l = qarr[i].l, r = qarr[i].r, idx = qarr[i].idx, lca = qarr[i].lca;
// cout<<"at query: "<<l<<" "<<r<<" "<<idx<<" "<<lca<<endl;
        while(curr_lo < l){
            update(curr_lo);
            curr_lo++;
        }
        while(curr_lo > l){
            curr_lo--;
            update(curr_lo);
        }
        while(curr_hi > r){
            update(curr_hi);
            curr_hi--;
        }
        while(curr_hi < r){
            curr_hi++;
            update(curr_hi);
        }
// cout<<"cnt[0]: ";for(int i=1;i<=cc;i++)  cout<<cnt[i][0]<<" ";cout<<endl;
// cout<<"cnt[1]: ";for(int i=1;i<=cc;i++)  cout<<cnt[i][1]<<" ";cout<<endl;
// cout<<"cnt[2]: ";for(int i=1;i<=cc;i++)  cout<<cnt[i][2]<<" ";cout<<endl;
// cout<<"temp: ";for(int i=0;i<3;i++)	cout<<temp[i]<<" ";cout<<endl;
 
        if(lca == arr[l]){
        // cout<<"shit"<<endl;
            ans[idx] = temp[2] - temp[0] - temp[1];
        }
        else{
            update(lo[lca]);
            ans[idx] = temp[2] - temp[0] - temp[1];
            update(lo[lca]);
        }
    }

 
    for(int i=0;i<q;i++)
        printf("%lld\n", ans[i]);
    return 0;
}