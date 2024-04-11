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
const int N=100005;
vector<int> graf[N];
vector<int> special;
map<int,int> yes;
struct Node{
    int rank;
    int parent;
};
vector<Node> dsu;
void init(int n)
{
    dsu.resize(n);
    for(int i=0;i<n;i++)
    {
        dsu[i].rank=1;
        dsu[i].parent=i;
    }
}
int get(int tr)
{
    if(dsu[tr].parent==tr)
        return tr;
    return dsu[tr].parent=get(dsu[tr].parent);
}
void merge(int a,int b)
{
    a=get(a);
    b=get(b);
    if(dsu[a].rank==dsu[b].rank)
    {
        dsu[a].rank++;
        dsu[b].parent=a;
    }
    if(dsu[a].rank<dsu[b].rank)
        dsu[a].parent=b;
    if(dsu[a].rank>dsu[b].rank)
        dsu[b].parent=a;
}
bool test(int tr,int par)
{
    if(yes[tr])
        return true;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        if(test(p,tr))
            return true;
    }
    return false;
}
int main()
{
    int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=0;i<k;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        special.pb(a);
        yes[a]=true;
    }
    vector<pair<int,pair<int,int> > > edges;
	for(int i=0;i<m;i++)
    {
        int x,y,d;
        scanf("%i %i %i",&x,&y,&d);
        x--;
        y--;
        if(x!=y)
            edges.pb({d,{x,y}});
    }
    sort(all(edges));
    vector<pair<int,pair<int,int>> > dodate;
    init(n);
    for(auto p:edges)
    {
        int x=p.second.first;
        int y=p.second.second;
        //printf("%i %i\n",x,y);
        if(get(x)!=get(y))
        {
            merge(x,y);
            graf[x].pb(y);
            graf[y].pb(x);
            dodate.pb({p.first,{x,y}});
            //printf("%i-%i  %i\n",x,y,p.first);
        }
    }
    reverse(all(dodate));
    for(auto p:dodate)
    {
        if(test(p.second.first,p.second.second)&&test(p.second.second,p.second.first))
        {
            for(int i=0;i<k;i++)
            {
                printf("%i ",p.first);
            }
            return 0;
        }
    }
    assert(0);
    return 0;
}