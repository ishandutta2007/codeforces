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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int N=32;
ll broj[N];
void test()
{
    int n;
    ll k;
    scanf("%i %lld",&n,&k);
    int tt=0;
    if(n>31)
    {
        tt=n-31;
    }
    n=min(n,31);
    k--;
    ll tr=4;
    int siz=n-1;
    ll odseceni=0;
    while(k>0&&siz>=1)
    {
        ll br1=tr-1;
        ll br2=tr-3;
        odseceni+=min(k,(ll)br2*broj[siz]);
        k-=min(k,(ll)br2*broj[siz]);
        if(k==0)
            break;
        k-=br1;
        siz--;
        tr*=2;
    }
    if(k==0||k<0&&odseceni>=-1*k)
    {
        printf("YES %i\n",siz+tt);
    }
    else
    {
        printf("NO\n");
    }
}
int main()
{
	broj[0]=0;
	ll tr=1;
	for(int i=1;i<N;i++)
    {
        broj[i]=tr+broj[i-1];
        tr*=4;
    }
    int t;
    scanf("%i",&t);
    while(t--)
        test();
    return 0;
}