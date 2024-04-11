#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout<<min(a[n-2]-1,n-2)<<endl;
    }
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/