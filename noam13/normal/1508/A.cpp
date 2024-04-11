#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9+7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

int solve(){
    int n; cin>>n;
    vector<string> a(3);
    vi cnt(3);
    loop(i,0,3){
        cin>>a[i];
        for(auto &c:a[i]) c-='0', cnt[i] += c;
    }
    loop(i,0,3){
        loop(j,i+1,3){
            bool x = cnt[i] <= n, y = cnt[j] <= n;
            if (x && y){
                string b = a[i], c = a[j];
                int i = 0, j = 0;
                string ans;
                while(i<2*n && j<2*n){
                    if (!b[i] && !c[j]) ans += '0', i++, j++;
                    else{
                        ans += '1';
                        if (b[i]) i++;
                        if (c[j]) j++;
                    }
                }
                while(i<2*n) ans += b[i++]+'0';
                while(j<2*n) ans += c[j++]+'0';
                while(ans.size()<3*n) ans +='0';
                cout << ans << endl;
                return 0;
            }
            x = cnt[i] >= n, y = cnt[j] >= n;
            if (x && y){
                string b = a[i], c = a[j];
                int i = 0, j = 0;
                string ans;
                while(i<2*n && j<2*n){
                    if (b[i] && c[j]) ans += '1', i++, j++;
                    else{
                        ans += '0';
                        if (!b[i]) i++;
                        if (!c[j]) j++;
                    }
                }
                while(i<2*n) ans += b[i++]+'0';
                while(j<2*n) ans += c[j++]+'0';
                while(ans.size()<3*n) ans +='0';
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -D_GLIBCXX_DEBUG -o a & a
2
1
00
11
01
3
011001
111010
110001


*/