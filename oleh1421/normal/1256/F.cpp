#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=991987651ll;
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    string a,b;
    a=s;
    b=t;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (a!=b){
        cout<<"NO";
        return;
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]){
            cout<<"YES";
            return;
        }
    }
    int inv1=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (s[j]>s[i]) inv1++;
        }
    }
    int inv2=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (t[j]>t[i]) inv2++;
        }
    }
    inv1%=2;
    inv2%=2;
    if (inv1==inv2) cout<<"YES";
    else cout<<"NO";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
        cout<<endl;
    }
    return 0;
}