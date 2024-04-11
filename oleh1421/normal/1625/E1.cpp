#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
using namespace std;
const int N=310000;
const int L=20;
int a[N];
int up[N][L];
ll cnt[N][L];
ll find_ans(int l,int r){
    if (l>r) return 0;

}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='(')-(c==')');
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (a[i]==-1){
            if (!v.empty()) {
                up[v.back()][0]=i+1;
                v.pop_back();
            }
        } else v.push_back(i);
    }
    for (int i=1;i<L;i++){
        for (int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
    vector<pair<int,pair<int,int> > >seg;
    for (int i=1;i<=n;i++){
        if (up[i][0]){
//            cout<<i<<" "<<up[i][0]<<endl;
            seg.push_back({up[i][0]-i,{i,up[i][0]-1}});
        }
    }
    sort(seg.begin(),seg.end());
    for (auto cur:seg){
        cnt[cur.second.first][0]=1;
        int l=cur.second.first+1;
        int r=cur.second.second-1;
        ll cn=0ll;
        while (l<=r){
            cnt[cur.second.first][0]+=cnt[l][0];
            l=up[l][0];
            cn++;
        }
        cnt[cur.second.first][0]+=cn*(cn-1ll)/2ll;
    }
    for (int i=1;i<L;i++){
        for (int j=1;j<=n;j++){
            cnt[j][i]=cnt[j][i-1]+cnt[up[j][i-1]][i-1];
        }
    }
    for (int i=1;i<=q;i++){
        int type,l,r;cin>>type>>l>>r;
        ll res=0ll;
        ll cn=0ll;
        for (int j=L-1;j>=0;j--){
            if (up[l][j] && up[l][j]<=r){
                cn+=(1<<j);
                res+=cnt[l][j];
                l=up[l][j];
            }
        }
        while (l<=r){
//            cout<<l<<endl;
            res+=cnt[l][0];
            l=up[l][0];
            cn++;
        }
        res+=cn*(cn-1ll)/2ll;
        cout<<res<<endl;
    }




}
int32_t main()
{
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

2 1073741823
1073741823 0
**/