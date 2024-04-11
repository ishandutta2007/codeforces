#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

ll dist(ll x,ll y,ll x1,ll y1){
    return abs(x-x1)+abs(y-y1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll x,y,ax,ay,bx,by,lim=5e16;
	cin >> x >> y >> ax >> ay >> bx >> by;
	ll xs,ys,t;
	cin >> xs >> ys >> t;
	vector<pair<ll,ll> > points;
	while(x<lim&&y<lim){
        points.pb({x,y});
        x=ax*x+bx;
        y=ay*y+by;
	}
	int best=0;
	int n=points.size();
	for(int i=0;i<n;i++){
        ll tr=dist(xs,ys,points[i].f,points[i].s);
        int trsol=0;
        int nxt=i;
        while(tr<=t){
            trsol++;
            if(nxt==0)
                break;
            tr+=dist(points[nxt].f,points[nxt].s,points[nxt-1].f,points[nxt-1].s);
            nxt--;
        }
        if(nxt==0&&i<n-1){
            nxt=i+2;
            tr+=dist(points[i+1].f,points[i+1].s,points[0].f,points[0].s);
            while(tr<=t){
                trsol++;
                if(nxt==n)
                    break;
                tr+=dist(points[nxt-1].f,points[nxt-1].s,points[nxt].f,points[nxt].s);
                nxt++;
            }
        }
        best=max(best,trsol);
	}
	printf("%i\n",best);
    return 0;
}