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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	ll w;
	scanf("%lld",&w);
	vector<ll> cnt(8);
	for(int i=0;i<8;i++)
        scanf("%lld",&cnt[i]);
    vector<int> order;
    for(int i=0;i<8;i++)
        order.pb(i);
    ll sol=LLONG_MAX;
    do{
        ll ostatak=w;
        for(auto p:order)
        {
            ll need=ostatak/(p+1);
            need=min(need,cnt[p]);
            ostatak-=need*(p+1);
        }
        sol=min(sol,ostatak);
    }while(next_permutation(all(order)));

    int a=clock();
    while(clock()-a<1000)
    {
        ll ostatak=w;
        for(int p=7;p>=0;p--)
        {
            ll need=ostatak/(p+1);
            need=min(need,cnt[p]);
            if(ostatak-need*(p+1)<sol)
                sol=ostatak-need*(p+1);
            if(need!=0)
                need=rng()%need+1;
            ostatak-=need*(p+1);
        }
        sol=min(sol,ostatak);
    }
    while(clock()-a<1900)
    {
        ll ostatak=w;
        for(int p=0;p<8;p++)
        {
            ll need=ostatak/(p+1);
            need=min(need,cnt[p]);
            if(ostatak-need*(p+1)<sol)
                sol=ostatak-need*(p+1);
            if(need!=0)
                need=rng()%need+1;
            ostatak-=need*(p+1);
        }
        sol=min(sol,ostatak);
    }
    printf("%lld\n",w-sol);
    return 0;
}