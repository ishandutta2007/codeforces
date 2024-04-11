#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[200001][25];
int cn[200001];
vector<int>g[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
         int n,m;cin>>n>>m;
         vector<int>v;
         v.push_back(m%10);
         while ((v.back()+m)%10!=v[0]) v.push_back((v.back()+m)%10);
         int x=n/m;
         int sum=0ll;
         for (auto i:v) sum+=i;
         int res=sum*(x/((int)v.size()));
         for (int i=0;i<(x%((int)v.size()));i++) res+=v[i];
         cout<<res<<endl;
    }


    return 0;
}


///2007521364118