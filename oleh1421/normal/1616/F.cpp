#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=270;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
int ind[N][N];
int x[N],y[N],z[N];
int a[N*N][N];
int b[N*N];
int ans[N];
bool empt[N];
int bt[N*N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ind[i][j]=0;
        }
    }
    for (int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>z[i];
        ind[x[i]][y[i]]=ind[y[i]][x[i]]=i;
    }

    vector<pair<vector<int>,int> >v;
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            for (int t=j+1;t<=n;t++){
                if (ind[i][j] && ind[j][t] && ind[i][t]){
                    int need=0;
                    vector<int>xx={ind[i][j],ind[j][t],ind[i][t]};
                    vector<int>u;
                    for (int cur:xx){
                        if (z[cur]==-1) u.push_back(cur);
                        else need-=z[cur];
                    }
                    need%=3;
                    need+=3;
                    need%=3;
                    cnt++;
                    for (int k=1;k<=m;k++) a[cnt][k]=0;

                    for (int k:u) a[cnt][k]=1;
                    b[cnt]=need;
//                    cout<<u.size()<<endl;
//                    for (int x:u) cout<<x<<" ";
//                    cout<<endl;
//                    cout<<b[cnt]<<endl;
                    empt[cnt]=false;
                }
            }
        }
    }
    int good=0;
    vector<int>basis;
    for (int i=1;i<=cnt;i++){
//        cout<<i<<" "<<a[i][4]<<" "<<a[i][5]<<" "<<a[i][6]<<" "<<b[i]<<endl;

        for (int j:basis){
            int c=(9-a[i][bt[j]]*a[j][bt[j]])%3;
            for (int t=1;t<=m;t++){

                a[i][t]+=c*a[j][t];
                a[i][t]%=3;
            }
            b[i]+=c*b[j];
            b[i]%=3;

        }
//        cout<<i<<" "<<a[i][4]<<" "<<a[i][5]<<" "<<a[i][6]<<" "<<b[i]<<endl;
        bt[i]=-1;
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                bt[i]=j;
                break;
            }
        }
        if (bt[i]==-1){
            if (b[i]%3){
                cout<<-1<<endl;
                return;
            }
        } else {
            basis.push_back(i);
        }
    }
    for (int i=1;i<=m;i++){
        if (z[i]==-1) z[i]=0;
    }
    reverse(basis.begin(),basis.end());
    for (int i:basis){

        for (int j=1;j<=m;j++){
            if (z[j]!=-1){
                b[i]-=a[i][j]*z[j];
                b[i]%=3;
                b[i]+=3;
                b[i]%=3;
            }
        }
        z[bt[i]]=b[i]*a[i][bt[i]]%3;
    }


    for (int i=1;i<=m;i++){
        if (z[i]==0) z[i]=3;
        cout<<z[i]<<" ";
    }
    cout<<endl;
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
5
3 3
1 2 1
2 3 2
3 1 -1
3 3
1 2 1
2 3 1
3 1 -1
4 4
1 2 -1
2 3 -1
3 4 -1
4 1 -1
3 3
1 2 1
2 3 1
3 1 2
4 6
1 2 1
2 3 2
1 3 3
1 4 -1
2 4 -1
3 4 -1



**/