#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
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
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v={1};
    int sum=a[1];
    int tot=a[1];
    for (int i=2;i<=n;i++){
        if (2*a[i]<=a[1]){
            v.push_back(i);
            sum+=a[i];
        }
        tot+=a[i];
    }
    if (sum*2ll>tot){
        cout<<(int)v.size()<<endl;
        for (auto i:v) cout<<i<<" ";
    } else cout<<0;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/