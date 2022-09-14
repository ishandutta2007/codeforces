#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
int d[8];
int a[3][3];
int sum1[3];
int sum2[3];
int suf[10][3];
bool ok=false;
vector<int>v;
int ans[10];
vector<int>r;
void F(int pos){
    if (ok) return;
    if (pos==8){
        for (int i=1;i<=7;i++){
            ans[r[i]]=v[i-1];
        }
        reverse(ans+1,ans+8);
        for (int i=1;i<=7;i++) cout<<ans[i]<<" ";
        //cout<<endl;
        //for (int i=0;i<3;i++) cout<<sum1[i]<<" "<<sum2[i]<<endl;
        ok=true;
        return;
    }
    int cur=r[pos];
    int minx=d[cur];
    int maxx=0;
    for (int j=0;j<3;j++){
        if (cur&(1<<j)){
            minx=min(minx,a[1][j]-sum1[j]);
            maxx=max(maxx,sum2[j]-suf[pos+1][j]-a[2][j]);
        }
    }
    for (int i=maxx;i<=minx;i++){
        for (int j=0;j<3;j++) if (cur&(1<<j)) sum2[j]-=i;
        for (int j=0;j<3;j++) if (cur&(1<<j)) sum1[j]+=i;
        v.push_back(i);
       // cout<<i<<" "<<cur<<" "<<d[cur]<<endl;
        F(pos+1);
        v.pop_back();
        for (int j=0;j<3;j++) if (cur&(1<<j)) sum2[j]+=i;
        for (int j=0;j<3;j++) if (cur&(1<<j)) sum1[j]-=i;
    }
}
void solve(){
    for (int i=0;i<3;i++) sum1[i]=sum2[i]=0;
    int n=7;
    cin>>a[1][0]>>a[1][1]>>a[1][2]>>a[2][0]>>a[2][1]>>a[2][2];
    swap(a[1][0],a[1][2]);
    swap(a[2][0],a[2][2]);
    for (int i=1;i<=7;i++) cin>>d[8-i];
    r.clear();
    r.push_back(0);
    vector<pair<int,int> >random;
    for (int i=1;i<=7;i++) random.push_back({-d[i]*__builtin_popcount(i),i});
    sort(random.begin(),random.end());
    for (auto x:random) r.push_back(x.second);
    for (int i=7;i>=1;i--){
        for (int j=0;j<3;j++){
            if (r[i]&(1<<j)) sum2[j]+=d[r[i]];
            suf[i][j]=sum2[j];
        }
    }
    v.clear();
    ok=false;
    F(1);
    if (!ok) cout<<-1;
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}