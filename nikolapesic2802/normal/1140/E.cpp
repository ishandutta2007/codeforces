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
const int N=2e5+5;
const int mod=998244353;
int n,k;
vector<int> el(N);
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int powmod(int x,int k)
{
    if(k<=0)
        return 1;
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int calc(int levo,int desno,int cnt)
{
    if(cnt==0)
        return levo!=desno;
    if(cnt==1)
        return k-(levo!=-1)-(desno!=-1)+(levo!=-1&&levo==desno);
    int trsol;
    if(levo==-1)
        trsol=k;
    else
        trsol=k-1;
    if(desno==-1)
        trsol=mul(trsol,k-1);
    else
        trsol=mul(trsol,k-2);
    trsol=mul(trsol,powmod(k-1,cnt-2));
    if(desno!=-1)
        trsol=add(trsol,calc(levo,desno,cnt-2));
    return trsol;
}
int main()
{
	scanf("%i %i",&n,&k);
	for(int i=0;i<n;i++)
        scanf("%i",&el[i]);
    ll sol=1;
    for(int i=0;i<n;i++)
    {
        if(el[i]!=-1&&i+2<n&&el[i]==el[i+2])
        {
            sol=0;
        }
    }
    for(int i=0;i<n;i+=2)
    {
        if(el[i]==-1)
        {
            int levo,desno,cnt=1;
            if(i==0)
            {
                levo=-1;
            }
            else
            {
                levo=el[i-2];
            }
            i+=2;
            while(i<n)
            {
                if(el[i]!=-1)
                    break;
                cnt++;
                i+=2;
            }
            if(i>=n)
                desno=-1;
            else
                desno=el[i];
            sol=mul(sol,calc(levo,desno,cnt));
        }
    }
    for(int i=1;i<n;i+=2)
    {
        if(el[i]==-1)
        {
            int levo,desno,cnt=1;
            if(i==1)
            {
                levo=-1;
            }
            else
            {
                levo=el[i-2];
            }
            i+=2;
            while(i<n)
            {
                if(el[i]!=-1)
                    break;
                cnt++;
                i+=2;
            }
            if(i>=n)
                desno=-1;
            else
                desno=el[i];
            sol=mul(sol,calc(levo,desno,cnt));
        }
    }
    printf("%lld\n",sol);
    return 0;
}