#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
void solve(){
    ll a,s;cin>>a>>s;
    vector<int>b;
    while (a){
        if (s%10>=a%10){
            b.push_back(s%10-a%10);
            s/=10;
            a/=10;
        } else {
            b.push_back(s%10-a%10+10);
            s/=10;
            if (s%10!=1){
                cout<<-1<<endl;
                return;
            }
            s/=10;
            a/=10;
        }
    }
    while (s){
        b.push_back(s%10);
        s/=10;
    }
    while (!b.empty() && b.back()==0) b.pop_back();
    if (b.empty()) b.push_back(0);
    reverse(b.begin(),b.end());
    for (auto i:b) cout<<i;
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
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M