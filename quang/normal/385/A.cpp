#include <bits/stdc++.h>
#define FRO(i,a,b) for(int i=a; i>=b; i--)
#define FOR(i,a,b)  for(int i=a; i<=b; i++)
#define filein(t)  freopen(t , "r" , stdin)
#define fileout(t) freopen(t , "w" , stdout)
#define ll  long long
#define maxn 10005
#define ln 2000000003
#define oo 1000000007

using namespace std;

int a[maxn];
int b[maxn];
int n, k;

void nhap()
{
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
}

void xuli()
{
    FOR(i,1,n-1)
        b[i] = a[i] - a[i+1];
    cout<<max(0, *max_element(b+1, b+n) - k);
}

int main()
{
    //filein("inp.txt");
    //fileout("out.txt");
    nhap();
    xuli();
}