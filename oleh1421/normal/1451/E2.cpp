//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define endl '\n'
const int N=1000010;
int pref[N];
int ind[N];
void solve(){
    int n;cin>>n;
    pref[1]=0;
    for (int i=1;i<n;i++){
        cout<<"XOR "<<i<<" "<<i+1<<endl;
        int x;cin>>x;
        pref[i+1]=(pref[i]^x);
    }
    for (int i=1;i<=n;i++){
        if (!ind[pref[i]]) ind[pref[i]]=i;
        else {
            cout<<"AND "<<ind[pref[i]]<<" "<<i<<endl;
            int x;cin>>x;
            x^=pref[i];
            cout<<"! ";
            for (int j=1;j<=n;j++) cout<<(x^pref[j])<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<"AND "<<ind[0]<<" "<<ind[1]<<endl;
    int x;cin>>x;
    cout<<"AND "<<ind[0]<<" "<<ind[2]<<endl;
    int y;cin>>y;
    x|=y;
    cout<<"! ";
    for (int j=1;j<=n;j++) cout<<(x^pref[j])<<" ";
    cout<<endl;
///2 0 1 3
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*

3 0
aa
bcd
*/