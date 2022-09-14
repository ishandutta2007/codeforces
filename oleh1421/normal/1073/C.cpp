#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int x[1000001];
int y[1000001];
int n,x0,y0;
bool ok(int len){
     for (int l=1;l+len-1<=n;l++){
         int r=l+len-1;
         int curx=x[l-1]+x[n]-x[r];
         int cury=y[l-1]+y[n]-y[r];
         int dist=abs(x0-curx)+abs(y0-cury);
         if ((dist+len)%2==0 && dist<=len) {
            return true;
         }
     }
     return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int curx=0;
    int cury=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='L') curx--;
        if (c=='R') curx++;
        if (c=='U') cury++;
        if (c=='D') cury--;
        x[i]=curx;
        y[i]=cury;
    }
    cin>>x0>>y0;
    if (x0==x[n] && y0==y[n]){
        cout<<0;
        return 0;
    }
    if (!ok(n)){
        cout<<-1;
        return 0;
    }
    int l=0;
    int r=n;
    while (r-l>1){
        int m=(l+r)/2;
        if (ok(m)) r=m;
        else l=m;
    }
    cout<<r;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/
//C:\Users\Zver\Desktop\666\main.cpp|22|error: invalid conversion from 'std::pair<long long int, long long int>*' to 'long long int' [-fpermissive]|