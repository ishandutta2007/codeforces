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
		if(i>0&&i<sz(a))
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int N=1e6+6;
const int mod=998244353;
vector<int> dp(N,-1);
int calc(int tr,int maxx)
{
    if(tr==maxx)
        return tr;
    return ((ll)calc(tr+1,maxx)*(maxx-tr+2)+(ll)(maxx-tr+1)*tr)%mod;
}
int main()
{
	int n;
	cin >> n;
	n--;
	if(n==0)
        printf("1\n");
    else
        printf("%i\n",calc(1,n)+1);
    return 0;
}