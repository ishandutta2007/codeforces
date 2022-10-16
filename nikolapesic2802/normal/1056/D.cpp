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
const int N=1e5+5;
vector<vector<int> > graf(N);
vector<int> s(N);
void dfs(int tr,int par)
{
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        dfs(p,tr);
        s[tr]+=s[p];
    }
    if(s[tr]==0)
        s[tr]++;
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=2;i<=n;i++)
    {
        int a;
        scanf("%i",&a);
        graf[a].pb(i);
        graf[i].pb(a);
    }
    dfs(1,-1);
    vector<int> b;
    for(int i=1;i<=n;i++)
    {
        b.pb(s[i]);
    }
    sort(all(b));
    for(int i=0;i<n;i++)
    {
        printf("%i ",b[i]);
    }
    return 0;
}