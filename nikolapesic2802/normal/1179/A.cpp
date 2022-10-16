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

int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	deque<int> dq;
	int maxx=0;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        maxx=max(maxx,a);
        dq.pb(a);
    }
    vector<pair<ll,int> > query(q);
    vector<pair<int,int> > ans(q);
    for(int i=0;i<q;i++)
        scanf("%lld",&query[i].f),query[i].s=i;
    sort(all(query));
    int tr=0;
    for(int i=0;i<n-1;i++)
    {
        int a=dq[0],b=dq[1];
        dq.pop_front();
        dq.pop_front();
        while(tr<q&&query[tr].f==i+1)
            ans[query[tr].s]={a,b},tr++;
        if(a>=b)
            dq.pb(b),dq.push_front(a);
        else
            dq.pb(a),dq.push_front(b);
    }
    while(tr<q)
        ans[query[tr].s]={maxx,dq[((query[tr].f-1)%(n-1))+1]},tr++;
    for(int i=0;i<q;i++)
        printf("%i %i\n",ans[i].f,ans[i].s);
    return 0;
}