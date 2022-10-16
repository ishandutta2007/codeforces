#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct pt{
    ld x,y;
    pt operator+(pt a){return {a.x+x,a.y+y};}
    pt operator-(pt a){return {x-a.x,y-a.y};}
    pt operator*(ld d){return {x*d,y*d};}
    pt operator/(ld d){return {x/d,y/d};}
};
ostream& operator<<(ostream& os,pt a){os << '(' << a.x << ',' << a.y << ')';return os;}
bool operator<(pt a,pt b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
ld cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
struct line{
    pt v;
    ld c;
    line(pt a,pt b){
        v=b-a;
        c=cross(v,a);
    }
};
ld sol;
pt o,o1;
void update(pt a,pt b){
    line l1(a,b),l2(o1,o);
    ld d=cross(l2.v,l1.v);
    if(d==0)
        return;
    pt i=(l1.v*l2.c-l2.v*l1.c)/d;
    if(i.x>max(a.x,b.x)||i.x<min(a.x,b.x)||i.y>max(a.y,b.y)||i.y<min(a.y,b.y))
        return;
    sol=max(sol,i.x);
}
int main()
{
    o1={0,0};
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin >> n >> o.x >> o.y;
	vector<pt> v(n);
	ll xm=0,ym=0;
	for(int i=0;i<n;i++)
        cin >> v[i].x >> v[i].y,xm=max(xm,(ll)v[i].x),ym=max(ym,(ll)v[i].y);
    v.pb({xm,0});
    v.pb({0,ym});
    sort(all(v));
    vector<pair<ld,pt> > vv;
    for(int i=1;i<v.size();i++)
    vv.pb({atan2((v[i]-v[0]).y,(v[i]-v[0]).x),v[i]});
    sort(all(vv));
    vector<pt> hull;
    hull.pb(v[0]);
    for(auto p:vv){
        while((int)hull.size()>1&&cross(p.s-hull[hull.size()-2],hull.back()-hull[hull.size()-2])>=0)
            hull.pop_back();
        hull.pb(p.s);
    }
    for(int i=0;i<(int)hull.size();i++)
        update(hull[i],hull[(i+1)%hull.size()]);
    sol=o.x/sol;
    cout << fixed << setprecision(10) << sol;
    return 0;
}