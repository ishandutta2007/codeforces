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
	ll h;
	int n;
	scanf("%lld %i",&h,&n);
	vector<ll> sums(n);
	ll minn=0;
	for(int i=0;i<n;i++)
    {
        scanf("%lld",&sums[i]);
        if(i)
            sums[i]+=sums[i-1];
        minn=min(minn,sums[i]);
    }
    if(minn==0||(h+minn>0&&sums[n-1]>=0))
    {
        printf("-1\n");
        return 0;
    }
    ll takes;
    if(h+minn<=0)
        takes=0;
    else
    {
        h+=minn;
        sums[n-1]*=-1;
        takes=h/sums[n-1]+((h%sums[n-1])!=0);
        sums[n-1]*=-1;
        h-=minn;
    }
    h+=takes*sums[n-1];
    ll sol=takes*n;
    for(int i=0;i<n;i++)
    {
        if(h+sums[i]<=0)
        {
            sol+=i+1;
            break;
        }
    }
    printf("%lld\n",sol);
    return 0;
}