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

int n;
void solve(vector<pair<int,int> > prvi,vector<pair<int,int> > drugi){
    vector<pair<int,int> > b(n);
    vector<pair<pair<int,int>,int> > a(n),rev(n);
	for(int i=0;i<n;i++)
        a[i].f.f=prvi[i].f,a[i].f.s=prvi[i].s,b[i].f=drugi[i].f,b[i].s=drugi[i].s,a[i].s=i,rev[i]=a[i],swap(rev[i].f.f,rev[i].f.s);
    sort(all(a));
    sort(all(rev));
    multiset<int> r;
    multiset<int,greater<int> > l;
    int tr=0;
    for(auto p:rev){
        while(tr<n&&a[tr].f.f<=p.f.f){
            l.insert(b[a[tr].s].f);
            r.insert(b[a[tr].s].s);
            tr++;
        }
        if((*l.begin())>(*r.begin())){
            printf("NO\n");
            exit(0);
        }
        l.erase(l.find(b[p.s].f));
        r.erase(r.find(b[p.s].s));
    }
}
int main()
{
	scanf("%i",&n);
	vector<pair<int,int> > a(n),b(n);
	for(int i=0;i<n;i++)
        scanf("%i %i %i %i",&a[i].f,&a[i].s,&b[i].f,&b[i].s);
    solve(a,b);
    solve(b,a);
    printf("YES\n");
    return 0;
}