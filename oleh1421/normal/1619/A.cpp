#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const int N=1000100;
const ll mod=998244353;
void solve(){
    string s;cin>>s;
    if (s.size()%2){
        cout<<"NO\n";
        return;
    }
    for (int i=0;i<s.size()/2;i++){
        if (s[i]!=s[i+s.size()/2]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M