#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
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
const int N=1e5;
vector<vector<int> > graf(N);
vector<int> s(N);
vector<int> values(N);
void dfs(int tr,int par,int su,int d)
{
    //printf("%i %i %i %i\n",tr,par,su,d);
    if(d%2==1)
    {
        //printf("Usao za %i\n",tr);
        //cerr << tr;
        values[tr]=s[tr]-su;
        if(values[tr]<0)
        {
            printf("-1\n");
            exit(0);
        }
        su=s[tr];
    }
    else
    {
        if(s[tr]!=-1)
        {
            printf("-1\n");
            exit(0);
        }
        int v=INT_MAX;
        for(auto p:graf[tr])
        {
            if(p==par)
                continue;
            v=min(v,s[p]);
        }
        if(v!=INT_MAX){
            values[tr]=v-su;
            if(values[tr]<0)
            {
                printf("-1\n");
                exit(0);
            }
            su=v;
        }
    }
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        dfs(p,tr,su,d+1);
    }
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        graf[a].pb(i);
        graf[i].pb(a);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&s[i]);
    }
    dfs(0,-1,0,1);
    ll su=0;
    for(int i=0;i<n;i++)
    {
        //printf("%i: %i\n",i,values[i]);
        su+=values[i];
    }
    printf("%lld\n",su);
    return 0;
}