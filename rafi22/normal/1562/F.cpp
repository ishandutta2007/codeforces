#include <bits/stdc++.h>

#define int long long
#define ii int
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int X[100007];
int X1[100007];

bool prime[200007];

int cnt=0,n;

int ask(int i,int j)
{
    cnt++;
   // if(cnt>)
    cout<<"? "<<X[i]<<" "<<X[j]<<endl;
   // return X[i]*X[j]/__gcd(X[i],X[j]);
    int x;
    cin>>x;
    return x;
}
unordered_map<int,int>rozw;
int lc[107][107];
int ans[100007];

int mul(int a, int b, int mod) {
    int ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    }
    return ret;
}
int pollard_rho(int n, int c) {
    int x = 2, y = 2, i = 1, k = 2, d;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = __gcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

int greatest_factor(int n)
{
    if(n==1) return 0;
    if(n<=100000000)
    {
        int mx=0,t=n;
        int s=sqrt(n);
        for(ii i=2; i<=s; i++)
        {
            if(prime[i]) continue;
            if(t%i==0)
            {
                mx=i;
                t/=i;
                while(t%i==0) t/=i;
            }
        }
        if(t>1) mx=t;
        return mx;
    }
    int d=n;
    for (int i=2;d==n;i++) d=pollard_rho(n,i);
    return max(greatest_factor(d),greatest_factor(n/d));
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=200000;i++) rozw[i*(i-1)]=i;
    for(int i=2;i<=200000;i++)
    {
        if(prime[i]) continue;
        for(int j=2*i;j<=200000;j+=i) prime[j]=1;
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) X[i]=i;
        if(n>100) random_shuffle(X+1,X+n+1);
        for(int i=1;i<=n;i++) X1[X[i]]=i;
        if(n<=100)
        {
            memset(ans,0,sizeof ans);
            set<pair<int,pair<int,int>>>Q;
            int r,mx=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    lc[i][j]=ask(i,j);
                    lc[j][i]=lc[i][j];
                    mx=max(mx,lc[i][j]);
                    Q.insert({lc[i][j],{i,j}});
                }
            }
            r=rozw[mx];
            for(int i=r;i>r-n+1;i--)
            {
                pair<int,pair<int,int>>pr=*--Q.end();
                int pos=pr.nd.st;
                for(int j=1;j<=n;j++)
                {
                    if(j==pos) continue;
                    if(lc[pos][j]%i!=0) pos=pr.nd.nd;
                }
                ans[pos]=i;
                for(int j=1;j<=n;j++)
                {
                    Q.erase({lc[pos][j],{pos,j}});
                    Q.erase({lc[pos][j],{j,pos}});
                }
            }
            cout<<"! ";
            for(int i=1;i<=n;i++)
            {
                if(ans[i]) cout<<ans[i]<<" ";
                else cout<<r-n+1<<" ";
            }
            cout<<endl;
        }
        else
        {
            int p=-1,pos=0,lol=0;
            while(true)
            {
                if(cnt>3000) break;
                int x=rand()*rand()%n+1,y=rand()*rand()%n+1;
                if(x==y) continue;
                int l=ask(x,y);
                int mx=greatest_factor(l);
                if(mx<=p||mx<=100) continue;
               // cout<<mx<<endl;
                bool nie=0;
                int g=0;
                for(int i=0;i<30;i++)
                {
                    int z=rand()*rand()%n+1;
                    if(z==x) continue;
                    l=ask(x,z);
                    if(l%mx!=0)
                    {
                        nie=1;
                        break;
                    }
                    g=__gcd(g,l/mx);
                }
                if(!nie&&g==1)
                {
                    p=mx;
                    pos=x;
                    continue;
                }
                if(!nie) continue;
                g=0,nie=0;
                for(int i=0;i<30;i++)
                {
                    int z=rand()*rand()%n+1;
                    if(z==y) continue;
                    l=ask(y,z);
                    if(l%mx!=0)
                    {
                        nie=1;
                        break;
                    }
                    g=__gcd(g,l/mx);
                }
                if(!nie&&g==1)
                {
                    p=mx;
                    pos=y;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(i==pos) ans[i]=p;
                else ans[i]=ask(i,pos)/p;
            }
            cout<<"! ";
            for(int i=1;i<=n;i++) cout<<ans[X1[i]]<<" ";
            cout<<endl;
        }
    }

    return 0;
}