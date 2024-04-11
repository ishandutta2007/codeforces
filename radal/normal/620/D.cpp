#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e3+20,mod = 1e9+7,inf=2e9;
const long double eps = 0.0000001;
ll a[N],b[N];
vector<pair<ll,pll> >  ve;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int m;
    ll s1=0,s2=0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        s1+=a[i];
    }
    cin >> m;
    rep(i,0,m){
        cin >> b[i];
        s2+=b[i];
    }
    ll ans = abs(s1-s2);
    ll ans1 = ans+2;
    int i1,j1;
    rep(i,0,n){
        rep(j,0,m){
            if (ans1 > abs(s1-s2-2*a[i]+2*b[j])){
                ans1 = abs(s1-s2-2*a[i]+2*b[j]);
                i1 = i+1;
                j1 = j+1;
            }
        }
        rep(j,i+1,n){
            ve.pb({2*(a[i]+a[j]),{i,j}});
        }
    }
    if (n == 1 || m == 1){
        if (ans <= ans1) cout << ans << endl << 0 << endl;
        else{
            cout << ans1 << endl << 1 << endl;
            cout << i1 << ' ' << j1;
        }
        return 0;
    }
    ll ans2 = ans1+3;
    int i2,j2,i3,j3;
    sort(ve.begin(),ve.end());
    rep(i,0,m){
        rep(j,i+1,m){
            auto it = lower_bound(ve.begin(),ve.end(),make_pair(s1-s2+2*(b[i]+b[j]),make_pair(0,0)));
            ll val = abs(s1-s2+2*(b[i]+b[j])-(*it).X);
            if (ans2 > val){
                ans2 = val;
                i2 = (*it).Y.X+1;
                j2 = (*it).Y.Y+1;
                i3 = i+1;
                j3 = j+1;
            }
            if (it != ve.begin()){
                it--;
                val = abs(s1-s2+2*(b[i]+b[j])-(*it).X);
                if (ans2 > val){
                    ans2 = val;
                    i2 = (*it).Y.X+1;
                    j2 = (*it).Y.Y+1;
                    i3 = i+1;
                    j3 = j+1;
                }
            }
        }
    }
    cout << min({ans,ans1,ans2}) << endl;
    if (ans <= min(ans1,ans2)){
        cout << 0 << endl;
        return 0;
    }
    if (ans1 <= ans2){
        cout << 1 << endl;
        cout << i1 << ' ' << j1 << endl;
        return 0;
    }
    cout << 2 << endl;
    cout << i2 << ' ' << i3 << endl;
    cout << j2 << ' ' << j3 << endl;
    return 0;
}