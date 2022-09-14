#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int a[2020][2020];
int b[2020][2020];
int minx_row[35];
int maxx_row[35];
int minx_col[35];
int maxx_col[35];
void solve(){
    for (int i=0;i<=30;i++) minx_row[i]=maxx_row[i]=minx_col[i]=maxx_col[i]=-1;
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            b[i][j]=0;
            char c;cin>>c;
            if (c=='.') a[i][j]=0;
            else a[i][j]=(c-'a')+1;
            if (minx_row[a[i][j]]==-1){
                minx_row[a[i][j]]=i;
                maxx_row[a[i][j]]=i;
                minx_col[a[i][j]]=j;
                maxx_col[a[i][j]]=j;
            } else {
                minx_row[a[i][j]]=min(minx_row[a[i][j]],i);
                maxx_row[a[i][j]]=max(maxx_row[a[i][j]],i);
                minx_col[a[i][j]]=min(minx_col[a[i][j]],j);
                maxx_col[a[i][j]]=max(maxx_col[a[i][j]],j);
            }
        }
    }
    vector<pair<pair<int,int>,pair<int,int> > >v;
    int last=27;
    for (int i=1;i<=26;i++){
        if (minx_row[i]!=-1) last=i;
    }
    if (last==27){
        cout<<"YES\n";
        cout<<0<<endl;
        return;
    }
    int x,y,z,d;
    x=y=z=d=-1;
    for (int i=last;i>=1;i--){
        if (minx_row[i]==-1){
            minx_row[i]=x;
            maxx_row[i]=y;
            minx_col[i]=z;
            maxx_col[i]=d;
        } else {
            x=minx_row[i];
            y=maxx_row[i];
            z=minx_col[i];
            d=maxx_col[i];
        }
    }
    for (int i=1;i<=last;i++){
        if (minx_row[i]==-1) continue;
        if (minx_row[i]<maxx_row[i] && minx_col[i]<maxx_col[i]){
            cout<<"NO\n";
            return;
        }
        v.push_back({{minx_row[i],minx_col[i]},{maxx_row[i],maxx_col[i]}});
    }
    int cur=0;
    for (auto i:v){
        cur++;
        for (int x=i.first.first;x<=i.second.first;x++){
            for (int y=i.first.second;y<=i.second.second;y++){
                b[x][y]=cur;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!=b[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    cout<<(int)v.size()<<endl;
    for (auto i:v){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}