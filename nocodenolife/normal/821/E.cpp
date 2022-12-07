#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

ll n,k;
ll a[105];
ll c[105];

ll ans[16];
ll newstat[16];

ll mat[16][16];
ll res[16][16];
ll mul[16][16];

void multiply(int ax[16][16], int bx[16][16])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 16; k++)
                mul[i][j] += (ax[i][k]*bx[k][j])%mod;
            mul[i][j]%=mod;
        }
    }
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            ax[i][j] = mul[i][j];
        }
    }
}

void power(int ex)
{
    memset(res,0,sizeof(res));
    for(int i=0;i<16;i++)
        res[i][i]=1;
    while (ex > 0) {
        if (ex & 1ll) multiply(res,mat);
        ex >>= 1ll;
        multiply(mat,mat);
    }
    return;

}

void createMat(ll hei)
{
    memset(mat,0,sizeof(mat));
    mat[0][0]=1;
    mat[0][1] = 1;

    if(hei>=15)
    {
        mat[15][14]=1;
        mat[15][15]=1;
    }
    for(ll i=1;i<min(hei+1,15ll);i++)
    {
        mat[i][i-1]=1;
        mat[i][i] =1;
        mat[i][i+1]=1;
    } 
}

void updateVal()
{
    for(int i=0;i<16;i++)
    {
        newstat[i]=0;
        for(int j=0;j<16;j++)
        {
            newstat[i] += (res[i][j] * ans[j])%mod;
        }
        newstat[i]%=mod;
    }

    for(int i=0;i<16;i++)
    {
        ans[i]=newstat[i];
    }
}


i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    memset(ans,0,sizeof(ans));
    ll ax,bx,cx;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>ax>>bx>>cx;
        a[i] = ax;
        c[i] = cx;
    }
    a[n] = k;
    ans[0] = 1;
    
    ll st,en,maxh;
    for(ll i=0;i<n;i++)
    {
        st = a[i];
        en = a[i+1];
        maxh = c[i];

        for(ll j=maxh+1;j<16;j++)
        {
            ans[j]=0;
        }

        if(st==en)
            continue;
        createMat(maxh);
        power(en-st);
        updateVal();
        //cout<<"st :"<<st<<" en :"<<en<<" maxh :"<<maxh<<endl;
        //cout<<"Matrix"<<endl;
        //for(int j=0;j<16;j++)
        //{
            //for(int k=0;k<16;k++)
            //{
                //cout<<res[j][k]<<" ";
            //}
            //cout<<endl;
        //}
        //for(int j=0;j<16;j++)
        //{
            //cout<<ans[j]<<" ";
        //}
        //cout<<endl;
    }

    cout<<ans[0]<<endl;
}