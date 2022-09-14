#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;

void solve(){
    ll a,b;cin>>a>>b;
    vector<pair<int,int> >p;
    int d=2;
    while (d*d<=b){
        int cnt=0;
        while (b%d==0){
            b/=d;
            cnt++;
        }
        if (cnt){
            p.push_back({d,cnt});
        }
        d++;
    }
    if (b>1) p.push_back({b,1});
    ll res=1ll;
    for (int i=0;i<p.size();i++){
        int L=0;
        ll x=a;
        while (x%p[i].first==0){
            x/=p[i].first;
            L++;
        }
        for (int j=1;j<=min(L,p[i].second-1);j++) x*=p[i].first;
        res=max(res,x);
    }
    cout<<res<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
4 0 4
1 2 2 3
*/