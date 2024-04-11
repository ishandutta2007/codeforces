//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
int a[N];
int s[6][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'a'+1);
    }
//    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    vector<int>v={1,2,3};
    for (int it=0;it<6;it++){
        for (int i=1;i<=n;i++){
            s[it][i]=s[it][i-1]+(a[i]!=v[i%3]);
        }
        next_permutation(v.begin(),v.end());
    }
    for (int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        int res=r-l+1;
        for (int j=0;j<6;j++){
            res=min(res,s[j][r]-s[j][l-1]);
        }
        cout<<res<<endl;
    }


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 5
2 1 7 4
4 2
**/