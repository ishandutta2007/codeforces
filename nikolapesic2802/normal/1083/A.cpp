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
const int N=3e5+5;
vector<vector<pair<int,int> > > graf(N);
vector<ll> w(N);
ll sol=0;
void solve(int tr,int par)
{
    //printf("Resavam %i %i\n",tr,par);
    vector<ll> best;
    for(auto p:graf[tr])
    {
        if(p.first==par)
            continue;
        solve(p.first,tr);
        //printf("%i  %i: nasao %lld %lld\n",tr,p.first,w[p.first]-p.second,w[tr]);
        best.pb((ll)w[p.first]-p.second);
    }
    sort(all(best));
    reverse(all(best));
    if(best.size()>=2)
    {
        ll yes=(ll)w[tr]+best[0]+best[1];
        sol=max(yes,sol);
    }
    if(best.size()>=1)
    {
        if(best[0]>0)
        {
            w[tr]+=(ll)best[0];
        }
    }
    sol=max(sol,w[tr]);
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        a--;
        b--;
        graf[a].pb({b,c});
        graf[b].pb({a,c});
    }
    solve(0,-1);
    printf("%lld\n",sol);
    return 0;
}