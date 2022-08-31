#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

vector<int> pr;
vector<int> pr2;
vector<int> ask;

const int lim = 1e18;
const int lim2 = 1e9;

void pre()
{
    for(int i=2;i<=800;i++)
    {
        int ff = 1;
        
        for(int j=2;j<i;j++) if(i%j == 0) ff = 0;
            
        if(ff == 1) 
        {
            if(i > 177) pr2.pb(i);
            else pr.pb(i);
        }
    }
    
    int num = 1;
    
    for(auto x : pr)
    {
        if(num >= (lim/x)) ask.pb(num), num = 1;
        num*=x;
    }
    
    ask.pb(num);    
}

int res;
map<int,int> mp;

void analyse(int x)
{
    for(auto z : pr)
    {
        while(x % z == 0) mp[z]++,x/=z;
    }
    
    for(auto z : pr2)
    {
        while(x % z == 0) mp[z]++,x/=z;
    }
}

int tot;

int query(int x)
{
    tot--;
    
    cout << "? " << x << endl;
    cin >> x;
    analyse(x);
}

void ans(int x)
{
    cout << "! " << (x+x) << endl;
}

int give(int x)
{
    int num = 1;
    
    while(num < (lim2/x)) num*=x;
    
    return num;
}

void solve()
{
    tot = 22;
    
    mp.clear();
    
    for(auto x : ask) query(x);
   
    set<int> st;
   
    for(auto x : mp) st.insert(x.F);
    mp.clear();
    
    while(!st.empty())
    {
        int v1 = *st.begin();
        st.erase(v1);
        
        if(st.size() > 0)
        {
            int v2 = *st.begin();
            st.erase(v2);
            
            query(give(v1)*give(v2));
        }
        else query(give(v1));
    }
    
    vi go = pr2;
    
    while(tot > 0)
    {
        random_shuffle(pr2.begin(),pr2.end());
        
        int num = 1;
        
        while(go.size() > 0)
        {
            if(num < (lim/go.back()))
            {
                num*=go.back();
                go.pop_back();
            }
            else break;
        }
        
        query(num);
    }
    
    res = 1;
    for(auto x : mp) res*=(x.S + 1);
    ans(res);
}

signed main()
{   
    pre();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}