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
ll solve(int l,int r)
{
    int d=r-l+1;
    int add;
    if(l%2==1)
    {
        add=1;
    }
    else
    {
        add=-1;
    }
    int kol=d/2;
    ll sol=add*kol;
    kol*=2;
    //printf("%i %i\n",kol,d);
    d-=kol;
    if(d)
    {
        if(r%2==1)
        {
            sol-=r;
        }
        else
        {
            sol+=r;
        }
    }
    return sol;
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        printf("%lld\n",solve(l,r));
    }
    return 0;
}