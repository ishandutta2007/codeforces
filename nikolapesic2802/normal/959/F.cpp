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
int gaus[20],sz;
const int mod=1e9+7;
void add(int x)
{
    for(int i=19;i>=0;i--)
    {
        if(x&(1<<i))
        {
            if(!gaus[i])
            {
                gaus[i]=x;
                return;
            }
            x^=gaus[i];
        }
    }
    sz++;
}
bool can(int x)
{
    for(int i=19;i>=0;i--)
    {
        x=min(x,x^gaus[i]);
    }
    return x==0;
}
void mul(int &a,int b)
{
    a=((ll)a*b)%mod;
}
int pwrmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,mul(x,x))
        if(k&1)
            mul(ans,x);
    return ans;
}
int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	vector<int> a(n),sol(q),x(q);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
	vector<vector<int> > qu(n);
	for(int i=0;i<q;i++)
    {
        int l;
        scanf("%i %i",&l,&x[i]);
        l--;
        qu[l].pb(i);
    }
    for(int i=0;i<n;i++)
    {
        add(a[i]);
        for(auto p:qu[i])
        {
            if(can(x[p]))
            {
                sol[p]=pwrmod(2,sz);
            }
        }
    }
    for(int i=0;i<q;i++)
        printf("%i\n",sol[i]);
    return 0;
}