
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
int a[N];
int get(int l,int r){
    if (l>r) return 0;
    int res=r-l+1;
    int mn=1000000001;
    for (int i=l;i<=r;i++){
        mn=min(mn,a[i]);
    }
    vector<int>z={l-1};
    for (int i=l;i<=r;i++){
        a[i]-=mn;
        if (a[i]==0) z.push_back(i);
    }
    z.push_back(r+1);
    int sum=mn;

    for (int i=1;i<z.size();i++){
        sum+=get(z[i-1]+1,z[i]-1);
    }
    res=min(res,sum);
    return res;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>z={0};
    for (int i=1;i<=n;i++){
        if (a[i]==0) z.push_back(i);
    }
    z.push_back(n+1);
    int res=0;
    for (int i=1;i<z.size();i++){
        res+=get(z[i-1]+1,z[i]-1);
    }
    cout<<res<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}