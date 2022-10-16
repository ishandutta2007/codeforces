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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	ll n,b;
	scanf("%lld %lld",&n,&b);
	vector<pair<ll,int> > factors;
	for(int i=2;(ll)i*i<=b;i++)
    {
        int cnt=0;
        while(b%i==0)
        {
            cnt++;
            //factors.pb(i);
            b/=i;
        }
        if(cnt)
        factors.pb({i,cnt});
    }
    if(b!=1)
        factors.pb({b,1});
    ll minn=LLONG_MAX;
    for(auto p:factors)
    {
        ll tr=p.f;
        ll cnt=0;
        while(tr<=n)
        {
            ll brojeva=n-tr;
            cnt++;
            cnt+=brojeva/tr;
            if(LLONG_MAX/p.f<tr)
                break;
            tr*=p.f;
        }
        minn=min(minn,cnt/p.s);
    }
    printf("%lld\n",minn);
    return 0;
}