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

const int MAX = 3e6;
ii cnt[MAX];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n); loop(i,0,n) cin>>a[i].x, a[i].y = i+1;
    sort(all(a));
    fill(cnt, cnt+MAX, ii(-1,-1));
    loop(i,0,n){
        loop(j,0,i){
            int dif = a[i].x - a[j].x;
            ii p = {j, i};
            if (cnt[dif].x==-1) cnt[dif] = p;
            else{
                ii q = cnt[dif];
                if (q.y!=p.x && q.y!=p.y && q.x!=p.x && q.x!=p.y){
                    cout<<"YES"<<endl;
                    cout << a[p.x].y << " " << a[q.y].y << " ";
                    cout << a[p.y].y << " " << a[q.x].y << endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -D_GLIBCXX_DEBUG -o a & a
6
2 1 5 2 7 4


*/