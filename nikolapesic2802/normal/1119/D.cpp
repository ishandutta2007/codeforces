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
	int n;
	scanf("%i",&n);
	vector<ll> arr(n);
	for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    ll start=arr.size();
    vector<ll> cmon;
    cmon.pb(0);
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]-arr[i-1]>1)
            cmon.pb(arr[i]-arr[i-1]-1);
    }
    sort(all(cmon));
    vector<ll> sums;
    for(int i=0;i<cmon.size();i++)
    {
        sums.pb(cmon[i]);
        if(i)
            sums[i]+=sums[i-1];
    }
    int q;
    scanf("%i",&q);
    while(q--)
    {
        ll l,r;
        scanf("%lld %lld",&l,&r);
        ll d=r-l;
        l=0,r=cmon.size()-1;
        while(l<r)
        {
            ll m=(l+r+1)>>1;
            if(cmon[m]>d)
                r=m-1;
            else
                l=m;
        }
        ll sol=start+sums[l]+(cmon.size()-1-l)*(d)+d;
        printf("%lld ",sol);
    }
    return 0;
}