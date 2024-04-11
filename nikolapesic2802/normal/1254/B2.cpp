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

const int N=1e6+5;
vector<int> a(N);
vector<ll> le(N),ri(N),solle(N),solri(N);
int n;
ll sol=LLONG_MAX;
ll test(ll p)
{
    vector<int> tr;
    ll sum=0,sol1=0;
    for(int i=0;i<n;i++)
    {
        int ima=a[i]%p;
        if(sum+ima>=p)
        {
            tr.pb(p-sum);
            ima-=p-sum;
            int m=tr.size();
            for(int i=0;i<m;i++)
                le[i]=tr[i]+(i==0?0:le[i-1]);
            for(int i=1;i<m;i++)
                solle[i]=solle[i-1]+le[i-1];
            for(int i=m-1;i>=0;i--)
                ri[i]=tr[i]+(i==m-1?0:ri[i+1]);
            solri[m-1]=0;
            for(int i=m-2;i>=0;i--)
                solri[i]=solri[i+1]+ri[i+1];
            ll bst=LLONG_MAX;
            for(int i=0;i<m;i++)
                bst=min(bst,solle[i]+solri[i]);
            sol1+=bst;
            if(sol1>=sol)
                break;
            tr.clear();
            sum=0;
        }
        if(ima||tr.size())
            tr.pb(ima),sum+=ima;
    }
    return sol1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll sum=0;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),sum+=a[i];
    vector<ll> kandidati;
    for(int i=2;i<N;i++)
        if(sum%i==0)
        {
            kandidati.pb(i);
            while(sum%i==0)
                sum/=i;
        }
    if(sum!=1)
        kandidati.pb(sum);
    for(auto p:kandidati)
        sol=min(sol,test(p));
    if(kandidati.empty())
        sol=-1;
    printf("%lld\n",sol);
    return 0;
}