#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
using namespace std;
ll pw[20];
void solve(){
    ll n;cin>>n;
    int S;cin>>S;
    vector<int>v;
    ll cur=n;
    while (cur){
        v.push_back(cur%10ll);
        cur/=10ll;
    }
    int sum=0;
    for (int i:v) sum+=i;
    if (sum<=S){
        cout<<0<<endl;
        return;
    }
    for (int i=0;i<v.size();i++){
        int sum=1;
        ll num=pw[i+1];
        for (int j=i+1;j<v.size();j++){
            sum+=v[j];
            num+=(ll)v[j]*pw[j];
        }
        if (sum<=S){
            cout<<num-n<<endl;
            return;
        }
    }

}
int main()
{
    pw[0]=1ull;
    for (int i=1;i<=19;i++){
        pw[i]=(pw[i-1]*10ull);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}