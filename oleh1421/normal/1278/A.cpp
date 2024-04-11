#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
void solve(){
    string p,h;cin>>p>>h;
    int n=(int)h.size();
    int m=(int)p.size();
    sort(p.begin(),p.end());
    for (int i=0;i+m-1<n;i++){
        string cur="";
        for (int j=i;j<=i+m-1;j++) cur+=h[j];
        sort(cur.begin(),cur.end());
        if (p==cur){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}