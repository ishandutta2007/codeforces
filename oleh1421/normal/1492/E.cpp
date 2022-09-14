//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=1000000007ll;
const int A=1000100;
vector<int>a[N];
int n,m;
int cn[N];
void check(int x,int y,int r){
    vector<pair<int,int> >v;
    int A=-1,B=-1;
    for (int i=1;i<=n;i++){
        int cnt=cn[i]-(a[r][x]!=a[i][x])-(a[r][y]!=a[i][y]);
        if (cnt>2) return;
        if (cnt==2){
            A=a[i][x];
            B=a[i][y];
            break;
        }
        if (cnt==1) v.push_back({a[i][x],a[i][y]});
    }
    if (A!=-1){
        for (int i=1;i<=n;i++){
            int cnt=cn[i]-(a[r][x]!=a[i][x])-(a[r][y]!=a[i][y])+(A!=a[i][x])+(B!=a[i][y]);
            if (cnt>2) return;
        }
        a[r][x]=A;
        a[r][y]=B;
        cout<<"Yes\n";
        for (int i=1;i<=m;i++) cout<<a[r][i]<<" ";
        cout<<endl;
        exit(0);
        return;
    }
    int val=-1;
    bool ok=true;
    for (int i=1;i<v.size();i++){
        if (v[i].first==v[0].first) continue;
        if (val==-1 || val==v[i].second) val=v[i].second;
        else {
            ok=false;
        }
    }
    if (ok){
        a[r][x]=v[0].first;
        a[r][y]=val;
        if (val==-1) a[r][y]=1;
        cout<<"Yes\n";
        for (int i=1;i<=m;i++) cout<<a[r][i]<<" ";
        cout<<endl;
        exit(0);
    }
    for (int i=0;i<v.size();i++) swap(v[i].first,v[i].second);
    swap(x,y);
    val=-1;
    ok=true;
    for (int i=1;i<v.size();i++){
        if (v[i].first==v[0].first) continue;
        if (val==-1 || val==v[i].second) val=v[i].second;
        else {
            ok=false;
        }
    }
    if (ok){
        a[r][x]=v[0].first;
        a[r][y]=val;
        if (val==-1) a[r][y]=1;
        cout<<"Yes\n";
        for (int i=1;i<=m;i++) cout<<a[r][i]<<" ";
        cout<<endl;
        exit(0);
    }
    return;
}
int cnt[N];
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        a[i].resize(m+1);
        for (int j=1;j<=m;j++) cin>>a[i][j];
    }
    int r=-1,c=-1;
    for (int i=1;i<=n && r==-1;i++){
        for (int j=1;j<=m && r==-1;j++){
            if (a[i][j]!=a[1][j]){
                r=i,c=j;
            }
        }
    }
    if (r==-1 || m<=2){
        cout<<"Yes\n";
        for (int i=1;i<=m;i++) cout<<a[1][i]<<" ";
        cout<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cn[i]+=(a[r][j]!=a[i][j]);
        }
    }
    for (int i=1;i<=m;i++){
        if (i!=c){
            check(c,i,r);
        }
    }


    for (int i=1;i<=n;i++){
        cn[i]=0;
        for (int j=1;j<=m;j++){
            cn[i]+=(a[1][j]!=a[i][j]);
        }
    }
    for (int i=1;i<=m;i++){
        if (i!=c){
            check(c,i,1);
        }
    }
    cout<<"No\n";

}
int32_t main()
{
    srand(time(NULL));
//    freopen("subset.in","r",stdin);
//    freopen("subset.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*

4 3 5

*/