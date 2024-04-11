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
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9 + 7;

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

const int m = 'z'-'a'+1;
int solve(){
    string s; cin>>s;
    int n = s.size();
    if (n==1) return cout<<s<<endl,0;
    vi cnt(m);
    for(auto c:s) cnt[c-'a']++;
    auto nxt = [&](int i){
        while(i<m && cnt[i]==0) i++;
        return i;
    };
    vi ans(n);
    bool ok = 0;
    loop(c,0,m){
        if (cnt[c]==1){
            ans[0] = c; cnt[c]--;
            loop(i,1,n) ans[i] = nxt(0), cnt[ans[i]]--;
            ok = 1;
            break;
        }
    }
    if (!ok) loop(c1,0,m) {
        loop(c2,c1,m){
            if (c1==c2){ 
                int c = c1;
                if (cnt[c]<=1) continue;
                int amt = cnt[c]-2;
                if (amt*2>(n-2)) continue;
                ans[0] = ans[1] = c;
                cnt[c] = 0;
                loop(i,2,n){
                    int cc = nxt(0);
                    if (i==2 || amt==0 || (cc<c && amt*2-1<=(n-i-1))) ans[i] = cc, cnt[ans[i]]--;
                    else {
                        ans[i] = c, amt--;
                        if (i+1<n) i++, ans[i] = cc, cnt[ans[i]]--;
                    }
                }
                ok = 1;
                break;
            }
            else{
                if (cnt[c1]==0 || cnt[c2]==0) continue;
                int ind = -1;
                loop(i,0,m) if(i!=c1 && i!=c2 && cnt[i]>0){
                    if (ind==-1 || ind<c1) ind = i;
                }
                if (ind==-1){
                    ans[0] = c1, ans[1] = c2, cnt[c1]--, cnt[c2]--;
                    int i = 2;
                    loop(x,0,cnt[c2]) ans[i++] = c2;
                    loop(x,0,cnt[c1]) ans[i++] = c1;
                }
                else{
                    vi cc = cnt;
                    ans[0] = c1, ans[1] = c2, cnt[c1]--, cnt[c2]--;
                    if (ind<c1){
                        int i = 2;
                        while(i<n){
                            ans[i] = nxt(0);
                            if (ans[i]>=c1) break;
                            cnt[ans[i]]--;
                            i++;
                        }
                        loop(x,0,cnt[c2]) ans[i++] = c2;
                        loop(x,0,cnt[c1]) ans[i++] = c1;
                    }
                    else{
                        loop(i,2,n){
                            ans[i] = nxt(0);
                            if (ans[i-1]==c1 && ans[i]==c2) ans[i] = ind;
                            cnt[ans[i]]--;
                        }
                    }
                }
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }
    if (!ok) loop(i,0,n) ans[i] = nxt(0), cnt[ans[i]]--;
    loop(i,0,n) cout<<char('a'+ans[i]); cout<<endl;
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
g++ e.cpp -o a & a
8
ddddccccccc
bbbbccccccc
dddccccbbbbbbbbbb
bbbccccccc
ddddeeeeeccccccc
aaaaaaaaa
aaaaaaaaaccdd
aaaaaaaaabbb

3
vkcup
abababa
zzzzzz


*/