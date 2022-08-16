#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 4e4 + 10;
const int K = 105;
const int inf = 1e9;
const int INF = 1e9;

//https://github.com/nishant403/Competitive-Coding/blob/master/Ashishgup%20library/Persistent%20Segment%20Tree.cpp

int ct=0;
int root[N], st[21*N], lc[21*N], rc[21*N];

int build(int L, int R)
{
	int node = ++ct;
	if(L==R)
		return node;
	int M = (L+R)/2;
	lc[node] = build(L, M);
	rc[node] = build(M+1, R);
	return node;
}

int update(int onode, int L, int R, int pos , int val)
{
	int node = ++ct;
	if(L==R)
	{
		st[node] = st[onode] + val;
		return node;
	}
	int M = (L+R)/2;
	lc[node] = lc[onode];
	rc[node] = rc[onode];
	if(pos <= M)
		lc[node] = update(lc[onode], L, M, pos,val);
	else
		rc[node] = update(rc[onode], M+1, R, pos,val);
	st[node] = st[lc[node]] + st[rc[node]];
	return node;
}

int query(int nodev, int L, int R, int x,int y)
{
    if(y < L || R < x) return 0;
    
    if(x <= L && R <= y) return st[nodev];
    
	int M = (L+R)/2;
    
    return query(lc[nodev],L,M,x,y) + query(rc[nodev],M+1,R,x,y);
}

vector<int> id[N];
int a[N];
int n,k;
int nex[N];

int C(int l,int r)
{
    int rs = query(root[l],1,n,l,r);
    return rs;   
}

//https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html

vector<int> dp_before(N,inf), dp_cur(N,inf);

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    
    pair<int, int> best = {INF, -1};

    int temp = C(optl , mid);
    
    for (int k = optl; k <= min(mid, optr); k++) 
    {
        //remove k th element from temp
        if(nex[k] <= mid)
        {
            temp -= nex[k] - k;
        }
        
        best = min(best, {dp_before[k] + temp, k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

signed main()
{
    fast;
    
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    root[n+1] = build(1, n);
    
    for(int i=n;i>=1;i--)
    {
        int num = 0;
        
        if(id[a[i]].size() > 0)
        {
            nex[i] = id[a[i]].back();
            root[i] = update(root[i+1],1,n,id[a[i]].back(),id[a[i]].back() - i);   
        }
        else
        {
            nex[i] = n + n;
            root[i] = root[i+1];
        }
        
        id[a[i]].pb(i);
    }
    
    dp_before[0] = 0;
    for(int i=1;i<=n;i++) dp_before[i] = C(1,i);
    
    for(int i=2;i<=k;i++)
    {
        compute(1,n,1,n);
        
        for(int j=0;j<=n;j++)
        {
            dp_before[j] = dp_cur[j];
            dp_cur[j] = inf;
        }
    }
    
    cout << dp_before[n];
}