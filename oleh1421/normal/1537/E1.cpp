#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'a'+1);
        a[i+n]=a[i];
    }
    int ind=n;
    for (int i=2;i<=n;i++){
        bool better=false;
        for (int j=1;j<=n;j++){
            if (a[j]<a[i+j-1]){
                better=true;
                break;
            }
            if (a[j]>a[i+j-1]) break;
        }
        if (better){
            ind=i-1;
            break;
        }
    }
    string s="";
    for (int i=1;i<=ind;i++){
        s+=char('a'+a[i]-1);
    }
    while (s.size()<k) s=s+s;
    while (s.size()>k) s.pop_back();
    cout<<s<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
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