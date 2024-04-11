#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const int L=20;
int a[N],c[N];
ll S[N];
int up[N][L];
ll sum[N][L];
int h[N];
void solve(){
    int q;cin>>q>>a[1]>>c[1];
    sum[1][0]=a[1];
    S[1]=(a[1]*1ll)*(c[1]*1ll);
    for (int i=0;i<L;i++){
        up[1][i]=0;
        sum[1][i]=a[1];
    }
    h[1]=0;
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int v=it+1;
            cin>>up[v][0]>>a[v]>>c[v];
            up[v][0]++;
            sum[v][0]=a[v];
            h[v]=h[up[v][0]]+1;
            for (int i=1;i<L;i++){
                up[v][i]=up[up[v][i-1]][i-1];
                sum[v][i]=sum[v][i-1]+sum[up[v][i-1]][i-1];
            }
        } else {
            int v,w;cin>>v>>w;
            int Last=w;
            v++;
            ll tot=sum[v][L-1];
            ll A=0ll,B=0ll;
            int st=h[v];
            for (int i=L-1;i>=0;i--){
                if ((1<<i)>st) continue;
                int x=h[v]-st+(1<<i);
                int u=v;
                for (int j=0;j<L;j++){
                    if (x&(1<<j)) u=up[u][j];
                }
                if (a[u]){
                    st-=(1<<i);
                }
            }
            ll sum=0ll;
            for (int i=st;i<=h[v];i++){
                int u=v;
                int x=h[v]-i;
                for (int j=0;j<L;j++){
                    if (x&(1<<j)) u=up[u][j];
                }
                if (a[u]>=w){
                    sum+=(c[u]*1ll)*(w*1ll);
                    a[u]-=w;
                    w=0;
                    break;
                } else {
                    w-=a[u];
                    sum+=(c[u]*1ll)*(a[u]*1ll);
                    a[u]=0;
                }
            }
            cout<<Last-w<<" "<<sum<<endl;
        }
    }


}
int32_t main() {
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