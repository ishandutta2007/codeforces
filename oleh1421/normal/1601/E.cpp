//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int n,q,k;
int a[N];
int t[N];
const int L=20;
int up[N][L];
ll sum[N][L];
int r[N];
void solve(){
    cin>>n>>q>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    deque<int>dq;
    for (int i=1;i<=k;i++){
        while (!dq.empty() && dq.back()>a[i]) dq.pop_back();
        dq.push_back(a[i]);
    }
    t[k]=dq.front();
    for (int i=k+1;i<=n;i++){
        while (!dq.empty() && dq.back()>a[i]) dq.pop_back();
        dq.push_back(a[i]);
        if (dq.front()==a[i-k]) dq.pop_front();
        t[i]=dq.front();
    }

    r[n+1]=n+1;
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        for (int j=i+1;j<=n;j=r[j]){
            if (a[j]<a[i]){
                r[i]=j;
                break;
            }
        }
    }
    up[n+1][0]=n+1;
    for (int i=n;i>=1;i--){
        up[i][0]=n+1;
        for (int j=i+k;j<=n;j=up[j][0]){
            if (t[j]<t[i]){
                up[i][0]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n+1;i++){
        sum[i][0]=1ll*((up[i][0]-i)/k)*1ll*t[i];
    }
    for (int i=n+1;i>=1;i--){
        for (int j=1;j<L;j++){
            up[i][j]=up[up[i][j-1]][j-1];
//            if (up[i][j]==0) cout<<"OOK "<<up[i][j-1]<<endl;
            sum[i][j]=sum[i][j-1]+sum[up[i][j-1]][j-1];
        }
    }

    for (int it=1;it<=q;it++){
        int l,rr;cin>>l>>rr;
        int nxt=(r[l]-l+k-1)/k;
        if (l+(nxt-1)*k>=rr){
            cout<<((rr-l)/k+1ll)*a[l]<<endl;
            continue;
        }
        ll res=a[l]*1ll*nxt;

        l+=k*nxt;
        if (l<=rr){
            for (int i=L-1;i>=0;i--){
                if (up[l][i]<=rr){
                    res+=sum[l][i];
                    l=up[l][i];
                }
            }
            res+=1ll*((rr-l)/k+1ll)*1ll*t[l];
        }
        cout<<res<<endl;
    }

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
7 1 2
2 15 6 3 7 5 6
3 5

**/