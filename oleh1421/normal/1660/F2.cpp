#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=500010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int pref[N];
int a[N];
struct BITS{
    int t[N];
    void upd(int pos,int x){
        for (;pos<N;pos|=pos+1) t[pos]+=x;
    }
    int get(int pos){
        int res=0;
        for (;pos>=0;pos&=pos+1,pos--) res+=t[pos];
        return res;
    }
};
BITS T[3];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='+')*2-1;
        pref[i]=pref[i-1]+a[i];
    }
    vector<ll>cnt(3,0);
    T[0].upd(n,1);
    ll res=0;
    for (int i=1;i<=n;i++){
        int cur=(pref[i]%3+3)%3;
        res+=T[cur].get(n-pref[i]);
        T[cur].upd(n-pref[i],1);
    }



    for (int i=0;i<=n;i++){
        int cur=(pref[i]%3+3)%3;
        T[cur].upd(n-pref[i],-1);
    }
    cout<<res<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}