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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct pt{
    ll x,y;
    pt operator-(pt a){return {x-a.x,y-a.y};}
    ll operator*(pt a){return x*a.y-y*a.x;}
    pt operator+(pt a){return {x+a.x,y+a.y};}
    long double len(){
        return (long double)x*x+(long double)y*y;
    }
    bool operator<(pt a){
        if(x!=a.x)
            return x<a.x;
        return y<a.y;
    }
};
bool cmp(pt a ,pt b)
{
    ll x=a*b;
    if(x!=0) return x>0;
    return a.len()<b.len();
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<pt> points(n);
	for(int i=0;i<n;i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].y-=points[i].x*points[i].x;
    }
    sort(all(points));
    for(int i=n-1;i>=0;i--)
        points[i]=points[i]-points[0];
    sort(all(points),cmp);
    deque<pt> hull;
    for(auto p:points)
    {
        while(hull.size()>1&&(p-hull[hull.size()-1])*(p-hull[hull.size()-2])>=0)
            hull.pop_back();
        hull.pb(p);
    }
    hull.pb(hull.front());
    int cnt=0;
    for(int i=0;i<hull.size()-1;i++)
        if(hull[i+1].x<hull[i].x)
            cnt++;
    printf("%i\n",cnt);
    return 0;
}