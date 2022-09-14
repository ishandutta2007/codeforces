#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000001];
int pos[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
    for (int i=pos[n]-1;i>=1;i--){
        if (a[i]>a[i+1]){
            cout<<"NO";
            return 0;
        }
    }
    for (int i=pos[n]+1;i<=n;i++){
        if (a[i]>a[i-1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/