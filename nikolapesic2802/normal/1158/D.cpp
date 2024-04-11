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
    int x,y,i;
    pt operator-(pt a){return {x-a.x,y-a.y,i};}
};
bool operator<(pt a,pt b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool operator==(pt a,pt b){return a.x==b.x&&a.y==b.y;}
bool operator!=(pt a,pt b){return !(a==b);}
ll cross(pt a,pt b){return (ll)a.x*b.y-(ll)a.y*b.x;}
pt last;
int main()
{
	int n;
	scanf("%i",&n);
	vector<pt> points(n);
	for(int i=0;i<n;i++)
        scanf("%i %i",&points[i].x,&points[i].y),points[i].i=i+1;
    sort(all(points));
    string s;
    cin >> s;
    printf("%i ",points[0].i);
    last=points[0];
    vector<pt> ne;
    for(int i=1;i<n;i++)
        ne.pb(points[i]);
    points=ne;
    for(int i=0;i<n-2;i++)
    {
        vector<pt> ne;
        pt mn=points[0];
        if(s[i]=='R')
        {
            for(auto p:points)
                if(cross(p-last,mn-last)<0)
                    mn=p;
        }
        else
        {
            for(auto p:points)
                if(cross(p-last,mn-last)>0)
                    mn=p;
        }
        printf("%i ",mn.i);
        last=mn;
        for(int i=0;i<(int)points.size();i++)
            if(points[i]!=mn)
                ne.pb(points[i]);
        points=ne;
    }
    printf("%i\n",points[0].i);
    return 0;
}