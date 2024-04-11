#include<bits/stdc++.h>

using namespace std;

#define N 600'000

int n,a[N],b[N],c[N],ans[N];
pair<int,int> f[N][2];

void cmin(int &x,int y){x=min(x,y);}

int calc(int i,int x){
    if (f[i][0].first&&x!=f[i][0].first) return f[i][0].second;
    if (f[i][1].first&&x!=f[i][1].first) return f[i][1].second;
    return -1;
}
void solve(){
    cin>>n;
    vector<int> h{0};
    for (int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
        ans[i]=0x3f3f3f3f;
        h.push_back(a[i]);
        h.push_back(b[i]);
    }
    sort(h.begin(),h.end());
    vector<vector<int>> ins(n*2+2),inc(n*2+2),dec(n*2+2),qry(n*2+2);
    vector<int> cnt(n+2);
    for (int i=1;i<=n;++i){
        a[i]=lower_bound(h.begin(),h.end(),a[i])-h.begin();
        b[i]=lower_bound(h.begin(),h.end(),b[i])-h.begin();
        ins[a[i]].push_back(c[i]);
        ins[b[i]].push_back(c[i]);
        inc[a[i]].push_back(c[i]);
        dec[b[i]+1].push_back(c[i]);
        qry[a[i]].push_back(i);
        qry[b[i]].push_back(i);
    }
    f[0][0]=f[0][1]={0,0};
    int num=0;
    for (int i=1;i<=n*2;++i){
        f[i][0]=f[i-1][0];
        f[i][1]=f[i-1][1];
        for (int x:ins[i]){
            if (x!=f[i][0].first){
                f[i][1]=f[i][0];
                f[i][0]={x,i};
            }
            else{
                f[i][0]={x,i};
            }
        }
        for (int x:inc[i]){
            ++cnt[x];
            if (cnt[x]==1) ++num;
        }
        for (int x:dec[i]){
            --cnt[x];
            if (cnt[x]==0) --num;
        }
        for (int x:qry[i]){
            if (num>1) ans[x]=0;
        }
    }
    for (int i=1;i<=n;++i){
        int j=calc(a[i],c[i]);
        if (j>0) cmin(ans[i],h[a[i]]-h[j]);
        j=calc(b[i],c[i]);
        if (j>0) cmin(ans[i],h[b[i]]-h[j]);
        if (j>=a[i]) ans[i]=0;
    }
    f[n*2+1][0]=f[n*2+1][1]={0,0};
    for (int i=n*2;i;--i){
        f[i][0]=f[i+1][0];
        f[i][1]=f[i+1][1];
        for (int x:ins[i]){
            if (x!=f[i][0].first){
                f[i][1]=f[i][0];
                f[i][0]={x,i};
            }
            else{
                f[i][0]={x,i};
            }
        }
    }
    for (int i=1;i<=n;++i){
        int j=calc(a[i],c[i]);
        if (j>0) cmin(ans[i],h[j]-h[a[i]]);
        j=calc(b[i],c[i]);
        if (j>0) cmin(ans[i],h[j]-h[b[i]]);
    }
    for (int i=1;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}