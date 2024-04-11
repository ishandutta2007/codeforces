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
const int mod=998244353;
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
    int n;
    scanf("%i",&n);
    map<int,int> index;
    vector<int> niz(n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        niz[i]=a;
        index[a]=i;
    }
    int cnt=0;
    int tr=0;
    for(int i=0;i<n-1;i++)
    {
        int a=niz[i];
        tr=max(tr,index[a]);
        assert(tr>=i);
        if(tr==i)
            cnt++;
    }
    printf("%i\n",pwrmod(2,cnt));
    return 0;
}