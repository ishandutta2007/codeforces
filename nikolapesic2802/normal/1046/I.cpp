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
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct pt{
    ld x,y;
    pt operator-(pt a){return {x-a.x,y-a.y};}
    pt operator+(pt a){return {x+a.x,y+a.y};}
    pt operator/(ld d){return {x/d,y/d};}
    pt operator*(ld d){return {x*d,y*d};}
};
ld sq(pt a){return a.x*a.x+a.y*a.y;}
ld abs(pt a){return sqrtl(sq(a));}
ld mindist(pt a,pt b,pt c,pt d)
{
    ld X=a.x-c.x;
    ld Y=a.y-c.y;
    ld Kx=b.x-a.x-d.x+c.x;
    ld Ky=b.y-a.y-d.y+c.y;
    ld ca=Kx*Kx+Ky*Ky;
    ld cb=2*(X*Kx+Y*Ky);
    ld cc=X*X+Y*Y;
    if(ca==0)
        return sq(a-c);
    ld t0=-cb/2/ca;
    if(t0>1||t0<0)
    {
        ld v1=ca+cb+cc;
        ld v2=cc;
        return min(v1,v2);
    }
    return ca*t0*t0+cb*t0+cc;
}
int main()
{
	int n,d1,d2;
	scanf("%i %i %i",&n,&d1,&d2);
	vector<pt> a(n),b(n);
	for(int i=0;i<n;i++)
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    int ans=0;
    bool biloVece=true;
    if(abs(a[0]-b[0])<=d1)
        ans++,biloVece=false;
    for(int i=1;i<n;i++)
    {
        if(biloVece)
        {
            ld dist=sqrtl(mindist(a[i-1],a[i],b[i-1],b[i]));
            if(dist<=d1)
                ans++,biloVece=false;
        }
        if(abs(a[i]-b[i])>d2)
            biloVece=true;
    }
    printf("%i\n",ans);
    return 0;
}