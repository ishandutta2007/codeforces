#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=6;
int a[N],b[N];
int c[N*N];
vector<int>g[N*N],C[N*N];
int cnt[(1<<12)];
int mn[(1<<12)];
int take[N*N];
mt19937 rnd(time(NULL));
double random_double(){
    return (rnd()%1000000001)/1000000000.0;
}
int n,m;
ll res=1e9;
void F(int pos,ll cur){
    if (cur>=res) return;
    if (pos==n*m){
        res=cur;
        return;
    }
    bool can=true;
    for (int to:C[pos]){
        if (cnt[to]==0){
            can=false;
            break;
        }
    }
    if (can){
        F(pos+1,cur);
    }
    for (int to:g[pos]){
        cnt[to]++;
    }
    F(pos+1,cur+c[pos]);
    for (int to:g[pos]){
        cnt[to]--;
    }

}
void solve(){
    cin>>n>>m;
    int bal=0;
    for (int i=0;i<n;i++) cin>>a[i],bal+=a[i];
    for (int i=0;i<m;i++) cin>>b[i],bal-=b[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>c[i*m+j];
        }
    }
    if (bal>0){
        cout<<-1<<endl;
        return;
    }
    int k=0;
    for (int maskA=0;maskA<(1<<n);maskA++){
        for (int maskB=0;maskB<(1<<m);maskB++){
            int bal=0;
            for (int i=0;i<n;i++){
                if (maskA&(1<<i)) bal+=a[i];
            }
            for (int i=0;i<m;i++){
                if (maskB&(1<<i)) bal-=b[i];
            }
            if (bal>0){
//                cout<<maskA<<" "<<maskB<<endl;
                k++;
                mn[k]=1e9;
                int last=-1;
                for (int i=0;i<n;i++){
                    if (maskA&(1<<i)){
                        for (int j=0;j<m;j++){
                            if (maskB&(1<<j)) continue;
                            g[i*m+j].push_back(k);
                            mn[k]=min(mn[k],c[i*m+j]);
                            last=i*m+j;
                        }
                    }
                }
                C[last].push_back(k);
            }
        }
    }
    F(0,0ll);
    cout<<res<<endl;
//    for (int i=0;i<n*m;i++) cout<<take[i]<<" ";
//    cout<<endl;



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}