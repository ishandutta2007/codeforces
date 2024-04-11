#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
 
using namespace std;
 
vector<ll> mam;
 
const int nax = 1e5 + 5;
ll ans[nax][2];
char ansc[nax];
int c = 0;
 
void dodaj(ll p1,ll p2)
{
    c++;
    ans[c][0] = p1;
    ans[c][1] = p2;
    ansc[c] = '+';
    mam.pb(p1 + p2);
}
 
void xorr(ll p1,ll p2)
{
    c++;
    ans[c][0] = p1;
    ans[c][1] = p2;
    ansc[c] = '^';
    mam.pb(p1 ^ p2);
}
ll x, y;
 
ll euklides(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = euklides(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
ll pp(ll a,ll b)
{
    return a * b;
}
 
void go(ll x,ll a)
{
    if(a == 1) return;
    go(x,a/2);
    dodaj(pp(x,a/2),pp(x,a/2));
    if(a%2==1)
    {
        dodaj(pp(x,a-1),x);
    }
}
 
void kon(ll p1,ll p2)
{
    euklides(p1,p2,x,y);
    if(x < 0) return;
    
 
    y = -y;
 
    go(p1,x);
    go(p2,y);
 
    xorr(pp(p1,x),pp(p2,y));
 
    cout<<c<<endl;
 
    for(int i=1;i<=c;i++)
    {
        cout<<ans[i][0]<<" "<<ansc[i]<<" "<<ans[i][1]<<endl;
    }
    exit(0);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int z; cin>>z;
    mam.pb(z);
 
    while(mam.size() <= 1000)
    {
        int sz = mam.size();
        int x = rand()%sz;
        int y = rand()%sz;
        ll p1 = mam[x];
        ll p2 = mam[y];
        if(rand()%2)
        {
            dodaj(p1,p2);
        }
        else xorr(p1,p2);
    }
 
    for(int i=1;i<=100;i++)
    {
        ll x = mam[i];
        for(int j=0;j<=23;j++)
        {
            dodaj(x,x);
            x *= 2;
        }
    }
 
    while(mam.size() <= 5000)
    {
        int sz = mam.size();
        int x = rand()%sz;
        int y = rand()%sz;
        ll p1 = mam[x];
        ll p2 = mam[y];
        if(rand()%2)
        {
            dodaj(p1,p2);
        }
        else xorr(p1,p2);
    }
    x = 1;
    for(int i=0;i<5000;i++)
    {
        for(int j=0;j<5000;j++)
        {
            if(__gcd(mam[i],mam[j]) == 1)
            {
                int cnt = mam[i] % 2 + mam[j] % 2;
                if(cnt == 1)
                {
                    ll p1 = mam[i];
                    ll p2 = mam[j];
                    if(p1 % 2 == 0) swap(p1,p2);
                    kon(p1,p2);
                }
            }
        }
    }
 
 
 
 
    return 0;
}