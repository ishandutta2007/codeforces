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
int n;
vector<int> visited(2005);
vector<int> par(2005,-1);
vector<int> powr(2005);
void play(int pre)
{
    if(pre!=-1)
    {
        if(par[pre]!=-1&&visited[par[pre]]==0)
        {
            visited[par[pre]]=1;
            printf("%i\n",par[pre]);
            fflush(stdout);
            return;
        }
    }
    pair<int,int> sol=mp(-1,0);
    for(int i=1;i<=2*n;i++)
    {
        if(!visited[i])
        {
            if(par[i]!=-1)
            {
                sol=max(sol,mp(powr[i]-powr[par[i]],i));
            }
        }
    }
    if(sol.first!=-1)
    {
        visited[sol.second]=1;
        printf("%i\n",sol.second);
        fflush(stdout);
        return;
    }
    //printf("%i %i\n",sol.first,sol.second);
    for(int i=1;i<=2*n;i++)
    {
        if(!visited[i])
            sol=max(sol,mp(powr[i],i));
    }
    if(sol.first==-1)
        exit(0);
    printf("%i\n",sol.second);
    fflush(stdout);
    visited[sol.second]=1;
}
int main()
{
	int m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=2*n;i++){
        scanf("%i",&powr[i]);
        //printf("%i\n",powr[i]);
	}
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        par[a]=b;
        par[b]=a;
    }
    int t;
    scanf("%i",&t);
    for(int i=1;i<=n;i++)
    {
        /*for(int i=1;i<=2*n;i++)
        {
            printf("%i: %i\n",i,visited[i]);
        }*/
        if(t==2)
        {
            int p;
            scanf("%i",&p);
            visited[p]=1;
            play(p);
        }
        else
        {
            play(-1);
            int p;
            scanf("%i",&p);
            visited[p]=1;
        }
    }
    return 0;
}