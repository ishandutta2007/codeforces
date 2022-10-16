#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

const int mod=1e6+3,L=60;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){return (ll)a*b%mod;}
int pwrmod(int x,ll k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	if(n<L&&(1LL<<n)<k)
    {
        printf("1 1\n");
        return 0;
    }
	ll cnt=0;
	for(int i=1;i<L;i++)
        cnt+=(k-1)/(1LL<<i);
    int st=pwrmod(2,n);
    int b=mul(pwrmod(st,k-1),pwrmod(pwrmod(2,cnt),mod-2));
    if(k>=mod)
    {
        printf("%i %i\n",b,b);
        return 0;
    }
    int a=1;
    for(int l=1;l<k;l++)
    {
        int kol=0,i=l;
        while(i%2==0)
            i/=2,kol++;
        int tr=sub(st,l);
        tr=mul(tr,pwrmod(pwrmod(2,kol),mod-2));
        a=mul(a,tr);
    }
    printf("%i %i\n",sub(b,a),b);
    return 0;
}