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
	vector<ll> niz(n);
	for(int i=0;i<n;i++)
        scanf("%lld",&niz[i]);
    for(int i=1;i<n;i++)
        niz[i]+=niz[i-1];
    if(niz[n-1]%3!=0)
    {
        printf("0\n");
        return 0;
    }
    ll deo=niz[n-1]/3;
    vector<int> prvi,drugi;
    for(int i=0;i<n-1;i++)
    {
        if(niz[i]==deo)
            prvi.pb(i);
        if(niz[i]==2*deo)
            drugi.pb(i);
    }
    reverse(all(drugi));
    if(deo==0)
    {
        ll sol=(ll)prvi.size()*((ll)prvi.size()-1)/2;
        printf("%lld\n",sol);
        return 0;
    }
    ll sol=0;
    for(auto p:prvi)
    {
        while(drugi.size()&&drugi.back()<p)
            drugi.pop_back();
        sol+=drugi.size();
    }
    printf("%lld\n",sol);
    return 0;
}