#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=100010;
//#define int ll
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            if (a[i]<a[j]){
                v.push_back({a[j]-a[i],{j,i}});
            } else {
                v.push_back({a[i]-a[j],{i,j}});
            }
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (auto cur:v){
        int a=cur.second.first;
        int b=cur.second.second;
        cout<<"? "<<a<<" "<<b<<endl;
        string ans;cin>>ans;
        if (ans.size()==3){
            cout<<"! "<<a<<" "<<b<<endl;
            return;
        }
    }
    cout<<"! 0 0"<<endl;
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



//0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


/**
70368744177661
70368744177662
70368744177663

**/