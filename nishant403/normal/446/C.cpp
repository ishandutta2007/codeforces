#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int MOD = 1e9 + 9;
const int N = 3e5 + 1000;
const int BLK = 1000;

int a[N];
int b[N];
int fib[N];
pair<pii,pii> mat[N];

int fib_sum(int r)
{
    if(r <= 0) return 0;
    return fib[r+2] - 1;
}

int fib_sum(int l,int r)
{
    return fib_sum(r) - fib_sum(l-1);
}

pair<pii,pii> prod(pair<pii,pii> & A,pair<pii,pii> & B)
{
    pair<pii,pii> C;
    C.F.F = A.F.F*B.F.F + A.F.S*B.S.F;
    C.F.S = A.F.F*B.F.S + A.F.S*B.S.S;
    C.S.F = A.S.F*B.F.F + A.S.S*B.S.F;
    C.S.S = A.S.F*B.F.S + A.S.S*B.S.S;
    
    C.F.F %= MOD;
    C.F.S %= MOD;
    C.S.F %= MOD;
    C.S.S %= MOD;
    
    return C;
}

pair<pii,pii> add(pair<pii,pii> & A,pair<pii,pii> & B)
{
    pair<pii,pii> C;
    C.F.F = A.F.F + B.F.F;
    C.F.S = A.F.S + B.F.S;
    C.S.F = A.S.F + B.S.F;
    C.S.S = A.S.S + B.S.S;
    
    C.F.F %= MOD;
    C.F.S %= MOD;
    C.S.F %= MOD;
    C.S.S %= MOD;
    
    return C;
}


pair<pii,pii> sub(pair<pii,pii> & A,pair<pii,pii> & B)
{
    pair<pii,pii> C;
    C.F.F = A.F.F - B.F.F;
    C.F.S = A.F.S - B.F.S;
    C.S.F = A.S.F - B.S.F;
    C.S.S = A.S.S - B.S.S;
    
    C.F.F %= MOD;
    C.F.S %= MOD;
    C.S.F %= MOD;
    C.S.S %= MOD;
    
    return C;
}

vector<pii> upds;
pair<pii,pii> to_upd[N];

void solve()
{
   int n,q;
   cin >> n >> q;
    
   f(i,n) cin >> a[i];
    
   f(i,n) b[i] = a[i];
   f(i,n-1) b[i+1] += b[i]; 
    
   int t,l,r,x; 
    
   while(q--)
   {
       cin >> t >> l >> r;
       l--,r--;
       
       if(t == 1) 
       {
           upds.pb({l,r});
           
           if(upds.size() == BLK)
           {
               for(auto x : upds)
               {
                   to_upd[x.F] = add(to_upd[x.F],mat[1]);
                   to_upd[x.S + 1] = sub(to_upd[x.S + 1],mat[x.S - x.F + 2]);
               }
               
               pair<pii,pii> cur = {{0,0},{0,0}};
               
               for(int i=0;i<n;i++)
               {
                   cur = add(cur,to_upd[i]);
                   
                   a[i] += cur.S.F;
                   cur = prod(cur,mat[1]);
               }
               
               upds.clear();
               f(i,n) to_upd[i] = {{0,0},{0,0}};
               f(i,n) b[i] = a[i];
               f(i,n-1) b[i+1] += b[i];
           }
       }
       else
       {
           int res = b[r];
           if(l > 0) res -= b[l - 1];
           
           for(auto x : upds)
           {
               if(x.F > r) continue;
               else if(x.S < l) continue;
               else
               {
                   int L = max(l,x.F);
                   int R = min(r,x.S);
                   res += fib_sum(L - x.F + 1,R - x.F + 1);
               }
           }
           
           res %= MOD;
           if(res < 0) res += MOD;
           cout << res << '\n';
       }
   }
}

signed main()
{
    fib[1] = fib[2] = 1;
    for(int i=3;i<N;i++) fib[i] = (fib[i-1] + fib[i-2])%MOD;
    
    mat[0] = {{1,0},{0,1}};
    mat[1] = {{1,1},{1,0}};
    
    for(int i=2;i<N;i++) mat[i] = prod(mat[i-1],mat[1]);
    
    fast;
    solve();
}