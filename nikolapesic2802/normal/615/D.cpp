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

const int mod=1e9+7;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){return (ll)a*b%mod;}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    sort(all(a));
    vector<pair<int,int> > p;
    p.pb({a[0],1});
    for(int i=1;i<n;i++)
        if(a[i]==a[i-1])
            p.back().s++;
        else
            p.pb({a[i],1});
    n=p.size();
    vector<int> suf(n+1);
    suf[n]=1;
    for(int i=n-1;i>=0;i--)
        suf[i]=(ll)suf[i+1]*(p[i].s+1)%(mod-1);
    int le=1,sol=1;
    for(int i=0;i<n;i++){
        int tr=1;
        for(int j=0;j<=p[i].s;j++,tr=mul(tr,p[i].f))
            sol=mul(sol,pwrmod(tr,(ll)suf[i+1]*le%(mod-1)));
        le=(ll)le*(p[i].s+1)%(mod-1);
    }
    printf("%i\n",sol);
    return 0;
}