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
vector<int> a;
int n,m;
bool test(int mi)
{
    //printf("Testiram %i\n",mi);
    ll sum=0;
    for(int i=0;i<mi;i++)
        sum+=a[i];
    for(int i=mi;i<=n;i++)
    {
        int ostalo=i-mi;
        int br=ostalo/mi;
        ll s=(ll)br*(br+1)/2;
        s=s*mi;
        int r=ostalo%mi;
        s+=(ll)r*(br+1);
        //printf("%i: %lld %lld  %i %i %i\n",i,sum,s,ostalo,br,r);
        if(sum-s>=m)
        {
            return true;
        }
        sum+=a[i];
    }
    return false;
}
int main()
{
	scanf("%i %i",&n,&m);
	a.resize(n);
	ll sum=0;
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),sum+=a[i];
    sort(all(a));
    reverse(all(a));
    a.pb(-1);
    if(sum<m){
        printf("-1\n");
        return 0;
    }
    int l=1,r=n+1;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(test(m))
            r=m;
        else
            l=m+1;
    }
    if(l==n+1)
        l=-1;
    printf("%i\n",l);
    for(int i=n-1;i>0;i--)
    {

    }
    return 0;
}