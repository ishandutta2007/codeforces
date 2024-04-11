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
vector<int> a;
int get(int l,int r)
{
    if(l==0)
        return a[r];
    return a[r]-a[l-1];
}
map<int,priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > > intervals;
int main()
{
	int n;
	scanf("%i",&n);
	a.resize(n);
	for(int i=0;i<n;i++){
        scanf("%i",&a[i]);
        if(i)
            a[i]+=a[i-1];
	}

    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++)
        {
            intervals[get(l,r)].push({r,l});
        }
    int maxx=0;
    vector<pair<int,int> > res;
    for(auto p:intervals)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > s=p.s;
        int r=-1;
        int cnt=0;
        vector<pair<int,int> > sol;
        while(s.size())
        {
            if(s.top().s>r)
            {
                sol.pb({s.top().s,s.top().f});
                r=s.top().f;
                cnt++;
            }
            s.pop();
        }
        if(cnt>maxx)
        {
            maxx=cnt;
            res=sol;
        }
    }
    printf("%i\n",maxx);
    for(auto p:res)
        printf("%i %i\n",p.f+1,p.s+1);
    return 0;
}