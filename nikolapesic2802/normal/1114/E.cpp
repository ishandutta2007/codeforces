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

mt19937 rng(time(NULL));
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int lft=60;
bool ask(int x)
{
    lft--;
    printf("> %i\n",x);
    fflush(stdout);
    int a;
    scanf("%i",&a);
    assert(a!=-1);
    return a;
}
int ask2(int x)
{
    lft--;
    printf("? %i\n",x);
    fflush(stdout);
    int t;
    scanf("%i",&t);
    assert(t!=-1);
    return t;
}
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    srand(time(NULL));
	int n;
	scanf("%i",&n);
	int l=0,r=1e9;
	int ans;
	while(l<=r)
    {
        int m=(l+r)>>1;
        if(ask(m))
        {
            ans=m;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    l=ans+1;
    assert(lft>=30);
    //printf("%i\n",l);
    int cntt=0;
    vector<int> pos;
    for(int i=0;i<n;i++)
        pos.pb(i+1);
    shuffle(all(pos),rng);
    vector<int> numbers;
    numbers.pb(l);
    int d=0;
    while(lft&&pos.size())
    {
        int tr=pos.back();
        pos.pop_back();
        numbers.pb(ask2(tr));
    }
    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            d=gcd(d,abs(numbers[i]-numbers[j]));
        }
    }
    assert(d>0&&(ll)(n-1)*d<=l);
    int prvi=l-(n-1)*d;
    assert(prvi>=0);
    printf("! %i %i\n",prvi,d);
    return 0;
}