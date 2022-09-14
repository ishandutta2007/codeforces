//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=1000501;
const ll mod=1000000007ll;
const ll inf=1000000001ll;
ll n,p;
int k[N];
int cnt[N];
ll mult(ll a,ll b){
    return min(a*b,inf);
}
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2ll);
}
void solve(){
    cin>>n>>p;
    for (int i=1;i<=n;i++) cin>>k[i];
    if (p>1){
        sort(k+1,k+n+1);
        ll sum=0ll;
        vector<int>ans;
        for (int i=n;i>=1;i--){
            if (sum>=1){
                ans.push_back(-1);

                sum--;
            } else {
                ans.push_back(1);
//                cout<<i<<" "<<1<<endl;
                sum++;
            }
            if (sum){
                if (k[i]-k[i-1]>30){
                    for (int j=i-1;j>=1;j--){
                        ans.push_back(-1);
                    }
                    break;
                }
                for (int j=1;j<=k[i]-k[i-1];j++){
                    sum=mult(sum,p);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        ll res=0ll;
        for (int i=0;i<n;i++){
            res+=binpow(p,k[i+1])*ans[i];
//            cout<<i<<" "<<res<<endl;
            res%=mod;
        }
        cout<<(res+mod)%mod<<endl;
    } else {
        cout<<n%2<<endl;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//x+cnt[i]-4=j
//x=j+4-cnt[i];
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/