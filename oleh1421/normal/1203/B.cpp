#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int a[200001];
int cnt[200001];
int N=10000;
void solve(){
     int n;cin>>n;
     for (int i=1;i<=N;i++) cnt[i]=0;
     for (int i=1;i<=4*n;i++){
        int a;cin>>a;
        cnt[a]++;
     }
     for (int i=1;i<=N;i++){
        if (cnt[i]%2){
            cout<<"NO";
            return;
        }
        cnt[i]/=2;
     }
     int i=1;
     int j=N;
     int S=0;
     while (i<j){
        if (cnt[i]==0){
            i++;
            continue;
        }
        if (cnt[j]==0){
            j--;
            continue;
        }
        if (cnt[i]!=cnt[j]){
            cout<<"NO";
            return;
        }
        if (S && i*j!=S){
            cout<<"NO";
            return;
        }
        S=i*j;
        i++;
        j--;
     }
     if (i==j && cnt[i]){
        if (cnt[i]%2 || (S && i*i!=S)){
            cout<<"NO";
            return;
        }
     }
     cout<<"YES";

}
int32_t main() {
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