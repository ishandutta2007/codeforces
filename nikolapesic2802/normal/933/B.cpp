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

vector<int> poly;
ll p,k;
int maxx;
int n;
void add(int pos)
{
    maxx=max(maxx,pos);
    int d=pos+1;
    if(d&1)
    {
        poly[pos]++;
        if(poly[pos]==k)
            poly[pos]=0,add(pos+1);
    }
    else
    {
        poly[pos]--;
        if(poly[pos]<0)
            poly[pos]=k-1,add(pos+1);
    }
}
int main()
{
	scanf("%lld %lld",&p,&k);
	vector<int> num;
	ll pp=p;
	while(pp)
    {
        num.pb(pp%k);
        pp/=k;
    }
    n=num.size();
    maxx=n-1;
    poly.resize(2*n);
    for(int i=n-1;i>=0;i--)
    {
        int d=i+1;
        if(d&1)
        {
            poly[i]=num[i];
        }
        else
        {
            if(num[i])
            {
                poly[i]=k-num[i];
                add(i+1);
            }
        }
    }
    printf("%i\n",maxx+1);
    for(int i=0;i<=maxx;i++)
        printf("%i ",poly[i]);
    return 0;
}