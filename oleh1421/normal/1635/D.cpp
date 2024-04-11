#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll mod=1000000007;
const ll inf=4e18;
const int L=20;
ll F[N];
int a[N];
void solve(){
    int n,p;cin>>n>>p;
    F[0]=1;
    F[1]=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=2;i<=p;i++){
        F[i]=(F[i-1]+F[i-2])%mod;
    }
    for (int i=1;i<=p;i++){
        F[i]=(F[i-1]+F[i])%mod;
//        cout<<i<<" "<<F[i]<<endl;
    }
    sort(a+1,a+n+1);
    set<int>st;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        int x=a[i];
        bool need=true;
        while (x>0){
            if (st.find(x)!=st.end()){
                need=false;
                break;
            }
            if (x%2){
                x/=2;
            } else {
                if (x%4) break;
                x/=4;
            }
        }
        st.insert(a[i]);
        if (need){
            int cnt=0;
            while (a[i]>0){
                a[i]/=2;
                cnt++;
            }
            if (cnt<=p) res+=F[p-cnt];
        }
    }
    cout<<res%mod<<endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
12837720
**/