#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
const ll inf=1000000000000000001;
int a[N][N];
int b[N];
bool ok[N];
vector<int>v[N];
int can[N];
pair<pair<int,int>,int> ind[3][10*10*10];
void solve(){
    for (int i=0;i<3;i++){
        for (int j=0;j<1000;j++){
            ind[i][j]={{0,0},0};
        }
    }
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    for (int i=1;i<=m;i++){
        char c;cin>>c;
        b[i]=(c-'0');
    }
    for (int i=1;i<=m;i++) v[i].clear();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int val=0;
            for (int t=j;t>=max(1,j-2);t--){
                val*=10;
                val+=a[i][t];
                ind[j-t][val]={{t,j},i};
            }
        }
    }
    for (int i=1;i<=m;i++) can[i]=-1;
    can[0]=0;
    for (int i=1;i<=m;i++){
        int val=0;
        for (int j=i;j>=max(1,i-2);j--){
            val*=10;
            val+=b[j];
            if (j==i) continue;
            if (ind[i-j][val].second && can[j-1]!=-1){
                can[i]=j-1;
            }
        }
        for (int to:v[i]){
            if (can[to]!=-1){
                can[i]=to;
            }
        }
    }
    if (can[m]==-1){
        cout<<-1<<endl;
        return;
    }
    vector<pair<pair<int,int>,int> >ans;
    while (m){
        int val=0;
        for (int i=m;i>=can[m]+1;i--){
            val*=10;
            val+=b[i];
        }
        ans.push_back(ind[m-can[m]-1][val]);
        m=can[m];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;

}

/**

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/