#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 1e9+7;

const int MAX = 1e7 + 10;

struct SEG{
    int sz;
    vi a;
    SEG(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    SEG(vi &ar){
        for(sz=1;sz<ar.size();sz*=2);
        a.resize(2*sz);
        loop(i,0,ar.size()) a[i+sz] = ar[i];
        loopr(i,1,sz) a[i] = max(a[2*i], a[2*i+1]);
    }
    void update(int i, int x){
        a[i+=sz]=x;
        for(i/=2;i;i/=2) a[i] = max(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        int res = -INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi h(n+1); loop(i,1,n+1) cin>>h[i]; 
    vi b(n+1); loop(i,1,n+1) cin>>b[i];
    vii st; st.pb({0,-INF});
    vi dp(n+1); dp[0] = 0;
    SEG seg(n+1); seg.update(0, dp[0]);
    loop(i,1,n+1){
        while(h[st.back().x] > h[i]) st.pop_back();
        int j = st.back().x;
        st.pb({i, max(b[i] + seg.query(j, i-1), st.back().y)});
        dp[i] = st.back().y;
        seg.update(i, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}
/*
color a
cls
g++ temp.cpp -D_GLIBCXX_DEBUG -o a & a
5
1 4 3 2 5
-3 4 -10 2 7

5
1 2 3 5 4
1 5 3 2 4


2
2 1
-2 -3


*/