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

const int mod=998244353;
const int N=2e5+5;
int mul(int a,int b)
{
    return ((ll)a*b)%mod;
}
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int pwrmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int inv(int a)
{
    return pwrmod(a,mod-2);
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> there(n+1);
    vector<int> niz(n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        if(niz[i]!=-1)
            there[niz[i]]=1,cnt++;
    }
    cnt=n-cnt;
    vector<int> no;
    for(int i=1;i<=n;i++)
        if(!there[i])
            no.pb(i);
    int sol=mul(cnt,cnt-1);
    sol=mul(sol,inv(4));
    int l=0,r=no.size();
    int ii=inv(cnt);
    for(int i=0;i<n;i++)
    {
        if(niz[i]==-1)
        {
            l++;
            r--;
            continue;
        }
        int les=lower_bound(all(no),niz[i])-no.begin();
        int gr=no.size()-les;
        int a=mul(gr,ii);
        a=mul(a,l);
        sol=add(sol,a);
        a=mul(les,ii);
        a=mul(a,r);
        sol=add(sol,a);
    }
    ordered_set<int> o;
    for(int i=0;i<n;i++)
    {
        if(niz[i]!=-1)
        {
            sol=add(sol,o.size()-o.order_of_key(niz[i]));
            o.insert(niz[i]);
        }
    }
    printf("%i\n",sol);
    return 0;
}