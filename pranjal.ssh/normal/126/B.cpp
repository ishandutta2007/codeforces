#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

vi z_function(string s) 
{
    int n = s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
struct BIT1
{
    vector<int> t;
    int n;
    BIT1()
    {
            n=0;
            t.clear();
    }
    BIT1(int sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void clear(int sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void update(int i, int val)
    {
        while(i<=n)
        {
            t[i]+=val;
            i+=i&-i;
        }
    }
    int query(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=t[i];
            i-=i&-i;
        }
        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string s;
    cin>>s;
    int n=s.length();
    if(n<=2){cout<<"Just a legend";return 0;}
    vi z=z_function(s);
    int here=-1;
    BIT1 bt(n+5);    
    
    FOR(i,1,n-1)bt.update(z[i]+1,1);
    int no=n-1;
    
    NFOR(i,n-1,1)
    {
        bt.update(z[i]+1,-1);
        no--;
        if(i+z[i]==n)
        {
            if(bt.query(z[i])<no)
            here=i;
        }
    }
    if(here==-1)cout<<"Just a legend";
    else FOR(i,here,n-1)cout<<s[i];
    
    return 0;
}