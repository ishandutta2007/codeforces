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

const int N = 105;

string s[N];
int n,m,k;
pii st,en;
string t;

pii pos[26];

vector<pair<pii,int> > g[N][N];

inline int get_cost(int i,int j)
{
    if(s[i][j] >= 'a' && s[i][j] <= 'z') return 1;
    else return s[i][j] - '0';
}

void travel(pii p,pii q,int id)
{
    while(p.F < q.F)
    {
        pii nex = {p.F + 1,p.S};
        int cst = get_cost(p.F,p.S);
        
        if(k < cst)
        {
            cout << p.F + 1 << ' ' << p.S + 1;
            exit(0);
        }
        
        k -= cst;
        p = nex;
    }
    
    while(p.F > q.F)
    {
        pii nex = {p.F - 1,p.S};
        int cst = get_cost(p.F,p.S);
        
        if(k < cst)
        {
            cout << p.F + 1 << ' ' << p.S + 1;
            exit(0);
        }
        
        k -= cst;
        p = nex;
    }
    
    while(p.S < q.S)
    {
        pii nex = {p.F,p.S + 1};
        int cst = get_cost(p.F,p.S);
        
        if(k < cst)
        {
            cout << p.F + 1 << ' ' << p.S + 1;
            exit(0);
        }
        
        k -= cst;
        p = nex;
    }
    
    while(p.S > q.S)
    {
        pii nex = {p.F,p.S - 1};
        int cst = get_cost(p.F,p.S);
        
        if(k < cst)
        {
            cout << p.F + 1 << ' ' << p.S + 1;
            exit(0);
        }
        
        k -= cst;
        p = nex;
    }
    
    
    if(k <= 0)
    {
        cout << p.F + 1 << ' ' << p.S + 1;
        exit(0);
    }
}

void solve()
{
   cin >> n >> m >> k;
   f(i,n) cin >> s[i];
   cin >> st.F >> st.S;
   cin >> t;
   cin >> en.F >> en.S;
    
   st.F--,st.S--;
   en.F--,en.S--;
    
   f(i,n) f(j,m)
       if(s[i][j] >= 'a' && s[i][j] <= 'z') pos[s[i][j] - 'a'] = {i,j};
    
   for(auto x : t)
   {
       pii temp_des = pos[x - 'a'];
       travel(st,temp_des,x - 'a');
       st = temp_des;
   }
    
   travel(st,en,26);
    
   cout << en.F + 1 << ' ' << en.S + 1; 
}

signed main()
{
    fast;
    solve();
}