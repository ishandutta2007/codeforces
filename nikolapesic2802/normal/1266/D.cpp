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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	scanf("%i %i",&n,&m);
	vector<ll> money(n);
	for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        a--;b--;
        money[a]-=c;
        money[b]+=c;
	}
	vector<pair<ll,int> > pos;
	vector<pair<pair<int,int>,ll> > sol;
	for(int i=0;i<n;i++)
        if(money[i]>0)
            pos.pb({money[i],i});
    for(int i=0;i<n;i++){
        while(money[i]<0){
            ll k=min(-money[i],pos.back().f);
            money[i]+=k;
            pos.back().f-=k;
            sol.pb({{i,pos.back().s},k});
            if(pos.back().f==0)
                pos.pop_back();
        }
    }
    printf("%i\n",sol.size());
    for(auto p:sol)
        printf("%i %i %lld\n",p.f.f+1,p.f.s+1,p.s);
    return 0;
}