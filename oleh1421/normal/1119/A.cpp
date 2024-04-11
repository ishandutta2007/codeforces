#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int maxx[300001];
int minx[300001];
int c[300001];
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    int maxx=0;
    for (int i=2;i<=n;i++){
        if (c[1]!=c[i]) maxx=max(maxx,i-1);
    }
    for (int i=1;i<n;i++){
        if (c[n]!=c[i]) maxx=max(maxx,n-i);
    }
    cout<<maxx;
    return 0;
}