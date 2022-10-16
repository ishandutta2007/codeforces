#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second
#define all(x) x.begin(), x.end()

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
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}

const int N=1e5+5;
vector<int> f(N);
void add(int i,int x)
{
    for(;i<N;i+=i&(-i))
        f[i]+=x;
}
int get(int i)
{
    int ans=0;
    for(;i;i-=i&(-i))
        ans+=f[i];
    return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,p;
	scanf("%i %i",&n,&p);
	ll finTime=0;
	set<pair<ll,int> > events;
	set<int> cekaju;
	for(int i=0;i<n;i++)
    {
        int t;
        scanf("%i",&t);
        events.insert({t,i});
    }
    vector<ll> ans(n);
    set<int> inQ;
    inQ.insert(INT_MAX);
    deque<int> q;
    bool obrisi=0;
    while(events.size()||cekaju.size()||q.size())
    {
        while(events.size()&&(*events.begin()).f<=finTime){
            auto tr=*events.begin();
            events.erase(events.begin());
            int mn=*inQ.begin();
            if(tr.s<mn)
            {
                q.pb(tr.s);
                inQ.insert(tr.s);
            }
            else
                cekaju.insert(tr.s);
        }
        if(obrisi)
            inQ.erase(q.front()),q.pop_front(),obrisi=0;
        if(cekaju.size())
        {
            int tr=*cekaju.begin();
            if(tr<(*inQ.begin()))
                cekaju.erase(cekaju.begin()),q.pb(tr),inQ.insert(tr);
        }
        if(q.size())
        {
            int tr=q.front();
            obrisi=1;
            finTime+=p;
            ans[tr]=finTime;
            continue;
        }
        finTime=(*events.begin()).f;
    }
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]);
    return 0;
}