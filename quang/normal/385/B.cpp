#include <bits/stdc++.h>
#define FRO(i,a,b) for(int i=a; i>=b; i--)
#define FOR(i,a,b)  for(int i=a; i<=b; i++)
#define filein(t)  freopen(t , "r" , stdin)
#define fileout(t) freopen(t , "w" , stdout)
#define rep(i,n) for(int i=0; i<n; i++)
#define ll  long long
#define maxn 10005
#define ln 2000000003
#define oo 1000000007

using namespace std;

string st;
string w = "bear";
int b[maxn];
int dem = 0;

int n;

void nhap()
{
    cin>>st;
    n = st.size();
    st = " " + st;
}

void chuanbi()
{
    FOR(i,1,n-3)
    {
        string q = st.substr(i, 4);
        if(q == w) b[++dem] = i;
    }
}

void xuli()
{
    ll kq = 0;
    FOR(i,1,n-3)
    {
        int u = lower_bound(b+1, b+dem+1, i) - b;
        int vt = b[u];
        if(b[u] >= i) kq += n - b[u] - 2;
    }
    cout<<kq;
}

int main()
{
    //filein("inp.txt");
    //fileout("out.txt");
    nhap();
    chuanbi();
    xuli();
}