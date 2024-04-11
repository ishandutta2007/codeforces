#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int last=0;
    vector<int>v;
    for (int i=1;i<=n;i++){
        int mx=0;
        int ind=-1;
        for (int j=1;j<=n;j++){
            if (a[j]==0) continue;
            int cur=__gcd(a[j],last);
            if (cur>mx){
                mx=cur;
                ind=j;
            }
        }
        last=__gcd(last,a[ind]);
        v.push_back(a[ind]);
        a[ind]=0;

    }
    for (int i:v) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}