#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e6+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
ll n,m,k;
ll a[N][5],mx[N][5];
pll check(int len){
    ll ans  = inf;
    int l,r;
    deque<pll> m1,m2,m3,m4,m5;
    rep(i,0,n){
        if (!m1.empty() && i-m1.front().Y+1 > len) m1.pop_front();
        while(!m1.empty() && m1.back().X <= a[i][0]) m1.pop_back();
        m1.pb({a[i][0],i});
        mx[i][0] = m1.front().X;

        if (!m2.empty() && i-m2.front().Y+1 > len) m2.pop_front();
        while(!m2.empty() && m2.back().X <= a[i][1]) m2.pop_back();
        m2.pb({a[i][1],i});
        mx[i][1] = m2.front().X;

        if (!m3.empty() && i-m3.front().Y+1 > len) m3.pop_front();
        while(!m3.empty() && m3.back().X <= a[i][2]) m3.pop_back();
        m3.pb({a[i][2],i});
        mx[i][2] = m3.front().X;

        if (!m4.empty() && i-m4.front().Y+1 > len) m4.pop_front();
        while(!m4.empty() && m4.back().X <= a[i][3]) m4.pop_back();
        m4.pb({a[i][3],i});
        mx[i][3] = m4.front().X;

        if (!m5.empty() && i-m5.front().Y+1 > len) m5.pop_front();
        while(!m5.empty() && m5.back().X <= a[i][4]) m5.pop_back();
        m5.pb({a[i][4],i});
        mx[i][4] = m5.front().X;
    }
    rep(i,len-1,n){
        if (mx[i][0]+mx[i][1]+mx[i][2]+mx[i][3]+mx[i][4] < ans){
            ans = mx[i][0]+mx[i][1]+mx[i][2]+mx[i][3]+mx[i][4];
            l = i-len+1;
            r = i;
        }
    }
    if (ans > k)
        return {-1,-1};
    else 
        return {l,r};
    
}
pll binary(int l,int r){
    int mid;
    pll p = check(r);
    if (p.X != -1) return p;
    while (r-l > 1){
        mid = (l+r)/2;
        p = check(mid);
        if (p.X != -1) l = mid;
        else r = mid;
    }
    return check(l);
}
int main(){
    cin >> n >> m >> k;
    rep(i,0,n){
        rep(j,0,m){ 
            cin >> a[i][j];
        }
    }
    if (check(1).X == -1){
        rep(i,0,m) cout << 0 << ' ';
        return 0;
    }
    pll p = binary(0,n);
    int len = p.Y-p.X+1;
    ll ans  = inf;
    int l;
    deque<pll> m1,m2,m3,m4,m5;
    rep(i,0,n){
        if (!m1.empty() && i-m1.front().Y+1 > len) m1.pop_front();
        while(!m1.empty() && m1.back().X <= a[i][0]) m1.pop_back();
        m1.pb({a[i][0],i});
        mx[i][0] = m1.front().X;

        if (!m2.empty() && i-m2.front().Y+1 > len) m2.pop_front();
        while(!m2.empty() && m2.back().X <= a[i][1]) m2.pop_back();
        m2.pb({a[i][1],i});
        mx[i][1] = m2.front().X;

        if (!m3.empty() && i-m3.front().Y+1 > len) m3.pop_front();
        while(!m3.empty() && m3.back().X <= a[i][2]) m3.pop_back();
        m3.pb({a[i][2],i});
        mx[i][2] = m3.front().X;

        if (!m4.empty() && i-m4.front().Y+1 > len) m4.pop_front();
        while(!m4.empty() && m4.back().X <= a[i][3]) m4.pop_back();
        m4.pb({a[i][3],i});
        mx[i][3] = m4.front().X;

        if (!m5.empty() && i-m5.front().Y+1 > len) m5.pop_front();
        while(!m5.empty() && m5.back().X <= a[i][4]) m5.pop_back();
        m5.pb({a[i][4],i});
        mx[i][4] = m5.front().X;
    }
    rep(i,len-1,n){
        if (mx[i][0]+mx[i][1]+mx[i][2]+mx[i][3]+mx[i][4] < ans){
            ans = mx[i][0]+mx[i][1]+mx[i][2]+mx[i][3]+mx[i][4];
            l = i;
        }
    }
    rep(i,0,m) cout << mx[p.Y][i] << ' ';
    return 0;
}