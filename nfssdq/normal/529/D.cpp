#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

pair < pair< int, int>, int> pp[20001];
int res[20001], ccnt[20001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, t; cin >> n >> m >> t;
    REP(i, n){
        string s; cin >> s;
        int v = (s[0]-'0')*10 + (s[1]-'0');
        v = (v*60) + (s[3]-'0')*10 + (s[4]-'0');
        v = (v * 60) + (s[6]-'0')*10 + (s[7]-'0');
        pp[i] = mp( mp(v, v+t-1), i);
    }
    sort(pp, pp + n);
    int last = 0, cnt = 0, fl = 0, distinct = 0;
    REP(i, n){
        while(pp[last].xx.yy < pp[i].xx.xx) {
            ccnt[ res[ pp[last].yy ] ]--;
            if(ccnt[ res[pp[last].yy] ] == 0) distinct--;
            last++;
        }
        if(distinct == m) {
            fl = 1;
            res[pp[i].yy] = res[pp[i-1].yy];
            ccnt[ res[pp[i].yy] ]++;
        } else {
            res[pp[i].yy] = ++cnt;
            ccnt[ res[pp[i].yy] ]++;
            distinct++;
        }
    }
    if(distinct == m) fl = 1;
    if(fl == 0){
        cout << "No solution" << endl;
        return 0;
    }
    cout << cnt << endl;
    REP(i, n) cout << res[i] << endl;
}