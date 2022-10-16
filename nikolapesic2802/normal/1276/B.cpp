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

const int N=2e5+5;
vector<int> visited(N);
vector<vector<int> > graf(N);
int cnt,n,m,a,b,c,d;
bool imaA,imaB;
void dfs(int tr){
    if(tr==a)
        imaA=1;
    if(tr==b)
        imaB=1;
    cnt++;
    visited[tr]=1;
    for(auto p:graf[tr])
        if(!visited[p])
            dfs(p);
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
        scanf("%i %i %i %i",&n,&m,&a,&b);
        a--;b--;
        for(int i=0;i<n;i++)
            visited[i]=0,graf[i].clear();
        vector<pair<int,int> > edges;
        for(int i=0;i<m;i++)
            scanf("%i %i",&c,&d),edges.pb({c-1,d-1}),graf[c-1].pb(d-1),graf[d-1].pb(c-1);
        int sizA=0,sizB=0;
        visited[a]=1;
        for(auto p:graf[a])
            if(!visited[p])
            {
                imaB=0;
                cnt=0;
                dfs(p);
                if(!imaB)
                    sizA+=cnt;
            }
        for(int i=0;i<n;i++)
            visited[i]=0;
        visited[b]=1;
        for(auto p:graf[b])
            if(!visited[p])
            {
                imaA=0;
                cnt=0;
                dfs(p);
                if(!imaA)
                    sizB+=cnt;
            }
        printf("%lld\n",(ll)sizA*sizB);
	}
    return 0;
}