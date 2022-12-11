#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
int cnt[32];
const int mod = 1e9+7;
int qm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (ll)res*a%mod;
        a = (ll)a*a%mod; b>>=1; 
    }return res;
}
int main(){
    int n; cin>>n;
    fors(i,1,n+1) {
        int x; scanf("%d", &x);
        int t = 0;
        while(!(x&1)) t++,x>>=1; cnt[t]++;
    }
    ll ans = (qm(2,n)-qm(2,n-cnt[0]))%mod;
    int cur = n-cnt[0];
    for(int i = 1; i <= 30; ++i){
        if(cnt[i]){
            ans = (ans + qm(2,cur-1)-qm(2,cur-cnt[i]))%mod;
            cur -= cnt[i];
        }
    }
    ans = (ans + mod)%mod;
    cout<<ans<<endl;
    return 0;
}