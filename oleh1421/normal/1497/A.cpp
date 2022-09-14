//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=200010;
const int A=10000010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int res=0;
    vector<int>v,u;
    a[0]=-1;
    for (int i=1;i<=n;i++){
        if (a[i]!=a[i-1]) v.push_back(a[i]);
        else u.push_back(a[i]);
    }
    reverse(u.begin(),u.end());
    for (int i:v) cout<<i<<" ";
    for (int i:u) cout<<i<<" ";
    cout<<endl;
}
int main()
{

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
4
3
1 1 2
2 2
1 2 10
2 1 10
1

10 3
2

**/