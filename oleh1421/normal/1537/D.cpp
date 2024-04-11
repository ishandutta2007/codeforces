#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300055;
const ll mod=1000000007;
const ll inf=1e18;

void solve(){
    int n;cin>>n;
    if (n&(n-1)){
        if (n%2){
            cout<<"Bob\n";
        } else {
            cout<<"Alice\n";
        }
        return;
    }
    int k=0;
    while ((1<<k)<n) k++;
    if (k==0 || k%2){
        cout<<"Bob\n";
    } else {
        cout<<"Alice\n";
    }
}
int32_t main() {
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
    int n;cin>>n;
    if (n&(n-1)){
        if (n%2){
            cout<<"Bob\n";
        } else {
            cout<<"Alice\n";
        }
        return;
    }
    int k=0;
    while ((1<<k)<n) k++;
    if (k==0 || k%2){
        cout<<"Bob\n";
    } else {
        cout<<"Alice\n";
    }
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2