#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=110;
const int A=10000001;
int a[N][N];
void solve(){
    int n;cin>>n;
    if (n==2){
        cout<<-1<<endl;
        return;
    }
    while (true){
        vector<int>v;
        for (int i=0;i<n*n;i++) v.push_back(i+1);
        random_shuffle(v.begin(),v.end());
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=v.back();
                v.pop_back();
            }
        }
        bool ok=true;
        for (int i=2;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (abs(a[i-1][j]-a[i][j])==1) ok=false;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=2;j<=n;j++){
                if (abs(a[i][j]-a[i][j-1])==1) ok=false;
            }
        }
        if (ok) break;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}