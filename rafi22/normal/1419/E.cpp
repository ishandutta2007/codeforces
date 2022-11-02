#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
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

vector<pair<int,int>>p;

void gen(int n,int i,int j)
{
    if(j>=sz(p)||(sz(p)==2&&i!=j))
    {
        if((n!=p[i].st*p[(i+1)%sz(p)].st&&n!=p[i].st*p[(i-1+sz(p))%sz(p)].st)||sz(p)==1) cout<<n<<" ";
        return ;
    }
    int x;
    if(i==j) x=p[j].st;
    else x=1;
    for(int l=(i==j);l<=p[j].nd;l++)
    {
        gen(n*x,i,j+1);
        x*=p[j].st;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k=2,sq;
        cin>>n;
        p.clear();
        sq=sqrt(n);
        while(n>1&&k<=sq)
        {
            int x=0;
            while(n%k==0)
            {
                n/=k;
                x++;
            }
            if(x) p.pb({k,x});
            k++;
        }
        if(n>1) p.pb({n,1});
        if(sz(p)==1)
        {
            for(int i=0; i<sz(p); i++) gen(1,i,i);
            cout<<endl<<0<<endl;
        }
        else if(sz(p)==2)
        {
            if(p[0].nd==1&&p[1].nd==1)
            {
                cout<<p[0].st<<" "<<p[1].st<<" "<<p[0].st*p[1].st<<endl;
                cout<<1<<endl;
            }
            else
            {
                gen(1,0,0);
                cout<<p[0].st*p[1].st<<" ";
                gen(1,1,1);
                int x=p[0].st;
                for(int i=1;i<=p[0].nd;i++)
                {
                    int y=p[1].st;
                    for(int j=1;j<=p[1].nd;j++)
                    {
                        if(i!=1||j!=1) cout<<x*y<<" ";
                        y*=p[1].st;
                    }
                    x*=p[0].st;
                }
                cout<<endl<<0<<endl;
            }
        }
        else
        {
            for(int i=0; i<sz(p); i++)
            {
                gen(1,i,i);
                cout<<p[i].st*p[(i+1)%sz(p)].st<<" ";
            }
            cout<<endl<<0<<endl;
        }
    }

    return 0;
}