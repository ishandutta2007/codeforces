#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1);
}
int a[N],b[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,l,r;
        cin >> n >> l >> r;
        rep(i,1,n+1){
            a[i] = 0;
            b[i] = 0;
        }
        rep(i,0,n){
            int x;
            cin >> x;
            if (i < l) a[x]++;
            else b[x]++;
        }
        int ans = 0;
        int cnt1=0,cnt2=0;
        rep(i,1,n+1){
            int x = min(a[i],b[i]);
            a[i] -= x;
            b[i] -= x;
            cnt1 += a[i];
            cnt2 += b[i];
        }
        if (cnt1 > cnt2){
            swap(cnt1,cnt2);
            rep(i,1,n+1) swap(a[i],b[i]);
        }
        int t = 0;
        rep(i,1,n+1) t += (b[i]&1);
        int x = min(cnt1,t);
        ans += x;
        rep(i,1,n+1){
            if (x && (b[i]&1)){
                x--;
                b[i]--;
                cnt1--;
                t--;
                cnt2--;
            }
        }
        if (t){
            ans += (cnt2-t)/2+t;
            cout << ans << endl;
            continue;
        }
        ans += cnt1;
        ans += (cnt2-cnt1)/2;
        cout << ans << endl;
    }
}