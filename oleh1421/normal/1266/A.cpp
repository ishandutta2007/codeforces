#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
int cnt[10];
void solve(){
    string s;cin>>s;
    int sum=0;
    int cnt0=0;
    int cnt2=0;
    for (auto i:s){
        if (i=='0') cnt0++;
        if ((i-'0')%2==0) cnt2++;
        sum+=(i-'0');
    }
    if (sum%3 || !cnt0 || cnt2<2) cout<<"cyan\n";
    else cout<<"red\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}