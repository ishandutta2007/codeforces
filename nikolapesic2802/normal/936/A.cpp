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
	ll k,d,t;
	scanf("%lld %lld %lld",&k,&d,&t);
	ll l=1,r=1e18+5;
	while(l<r)
    {
        ll m=(l+r)>>1;
        if(LLONG_MAX/m<d)
        {
            r=m-1;
            continue;
        }
        if(m*d>=k)
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    assert(l*d>=k);
    ll waste=l*d-k;
    //printf("%lld %lld\n",k,waste);
    t*=2;
    ll per=k*2+waste;
    ll time_per=k+waste;
    //printf("%lld %lld\n",per,time_per);
    l=0,r=1e18+5;
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        if(LLONG_MAX/m<per)
        {
            r=m-1;
            continue;
        }
        if(m*per<=t)
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    ll ostalo=t-l*per;
    assert(ostalo>=0);
    ll time=time_per*l;
    if(ostalo<=2*k)
    {
        printf("%lld",time+ostalo/2);
        if(ostalo%2==1)
            printf(".5");
    }
    else
    {
        time+=k;
        time+=ostalo-2*k;
        printf("%lld",time);
    }
    return 0;
}