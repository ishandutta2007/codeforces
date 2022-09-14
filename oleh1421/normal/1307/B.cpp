#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
unordered_map<int,int>mp;
const int N=210001;
int a[N];
void solve(){
    int n,x;cin>>n>>x;
    int mx=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if (x<mx){
        for (int i=1;i<=n;i++){
            if (a[i]==x){
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
        return;
    }
    cout<<(x+mx-1)/mx<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4 5 3
3 4
2 4
2 2
3
2 1 4 5
1 2 1 4
2 3 4 4
*/