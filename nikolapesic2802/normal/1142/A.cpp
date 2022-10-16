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
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll nzs(ll a,ll b)
{
    return a/gcd(a,b);
}
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	int a,b;
	scanf("%i %i",&a,&b);
	ll l1=a+b;
	ll l2=k-a+b;
	ll l3=a+k-b;
	ll l4=k-a+k-b;
	ll minn=LLONG_MAX,maxx=LLONG_MIN;
	ll dist=(ll)n*k;
	for(int i=0;i<=n;i++)
    {
        minn=min(minn,nzs(dist,l1));
        maxx=max(maxx,nzs(dist,l1));
        minn=min(minn,nzs(dist,l2));
        maxx=max(maxx,nzs(dist,l2));
        minn=min(minn,nzs(dist,l3));
        maxx=max(maxx,nzs(dist,l3));
        minn=min(minn,nzs(dist,l4));
        maxx=max(maxx,nzs(dist,l4));
        l1+=k;
        l2+=k;
        l3+=k;
        l4+=k;
    }
    printf("%lld %lld\n",minn,maxx);
    return 0;
}