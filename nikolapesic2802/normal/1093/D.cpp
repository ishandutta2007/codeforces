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
const int N=3e5+5;
vector<vector<int> > graf;
vector<int> powers(N);
vector<int> color;
vector<int> ver;
bool dfs(int tr)
{
    ver.pb(tr);
    for(auto p:graf[tr])
    {
        int c=color[tr]%2+1;
        if(color[p]!=0&&color[p]!=c)
            return false;
        if(color[p]==0){
            color[p]=c;
            if(!dfs(p))
                return false;
        }
    }
    return true;
}
void test()
{
    int n,m;
    scanf("%i %i",&n,&m);
    graf.resize(n);
    color.resize(n);
    for(int i=0;i<n;i++)
        graf[i].clear(),color[i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        x--;
        y--;
        graf[x].pb(y);
        graf[y].pb(x);
    }
    int sol=1;
    for(int i=0;i<n;i++)
    {
        if(!color[i])
        {
            ver.clear();
            color[i]=1;
            if(!dfs(i))
            {
                printf("0\n");
                return;
            }
            int blue=0,red=0;
            for(auto p:ver)
                if(color[p]==1)
                    blue++;
                else
                    red++;
            sol=((ll)sol*(powers[blue]+powers[red]))%mod;
        }
    }
    printf("%i\n",sol);
}
int main()
{
    powers[0]=1;
    for(int i=1;i<N;i++)
        powers[i]=(powers[i-1]*2)%mod;
	int t;
	scanf("%i",&t);
	while(t--)
        test();
    return 0;
}