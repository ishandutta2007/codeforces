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

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}


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

int main()
{
    boost;
    string s,t;
    cin>>s>>t;
    int ns,nt;
    ns=sz(s),nt=sz(t);

    string sr=s;
    reverse(all(sr));

    int i=0;
    vii yay;
    bool gg=0;
    while(i<nt)
    {
        string a,b;
        FOR(j,i,nt-1)a+=t[j];
        a+="#";
        b=a;

        a+=s;
        b+=sr;

        // cout<<a<<" "<<b<<"\n";

        vi za=z_function(a);
        vi zb=z_function(b);

        int val=0;
        ii ans;

        FOR(j,nt+1-i,sz(za)-1)
        {
            if(za[j]>val)
            {
                val=za[j];
                ans.F=j-(nt+1-i);
                ans.S=j-(nt+1-i)+za[j]-1;
            }

        }
        FOR(j,nt+1-i,sz(zb)-1)
        {
            if(zb[j]>val)
            {
                val=zb[j];
                ans.F=j-(nt+1-i);
                ans.S=j-(nt+1-i)+zb[j]-1;

                ans.F=ns-ans.F-1;
                ans.S=ns-ans.S-1;
                if(ans.F<=ans.S)swap(ans.F,ans.S);
            }
        }

        i+=val;
        if(val==0)
        {
            cout<<"-1\n";return 0;
        }
        // if(i==3 and gg)break;
        // if(i==3)gg=1;
        yay.pb(ans);

    }
    cout<<sz(yay)<<"\n";

    tr(yay,it)
    {
        cout<<it->F+1<<" "<<it->S+1<<"\n";
    }
    return 0;
}