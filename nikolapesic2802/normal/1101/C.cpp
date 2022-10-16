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
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
struct node{
    int parent;
    int rank;
};
vector<node> DSU;
void init(int n)
{
    DSU.resize(n);
    DSU.clear();
    for(int i=0;i<n;i++)
        DSU[i].parent=i,DSU[i].rank=1;
}
int find(int tr)
{
    if(DSU[tr].parent==tr)
        return tr;
    return DSU[tr].parent=find(DSU[tr].parent);
}
void merge(int a,int b)
{
    a=find(a);b=find(b);
    if(DSU[a].rank==DSU[b].rank)
    {
        DSU[a].parent=b;
        DSU[b].rank++;
    }
    if(DSU[a].rank>DSU[b].rank)
    {
        DSU[b].parent=a;
    }
    if(DSU[a].rank<DSU[b].rank)
    {
        DSU[a].parent=b;
    }
}
void test()
{
    int n;
    scanf("%i",&n);
    init(n);
    vector<int> sets(n);
    set<int> open;
    vector<set<int> > graf(n);
    map<int,vector<int> > delta,era;
    set<int> cords;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        delta[l].pb(i);
        era[r+1].pb(i);
        cords.insert(l);
        cords.insert(r+1);
    }
    for(auto i:cords)
    {
        for(auto p:era[i])
            open.erase(p);
        for(auto p:delta[i])
        {
            if(open.size())
                merge(p,*open.begin());
            open.insert(p);
        }
    }
    set<int> pars;
    for(int i=0;i<n;i++)
        pars.insert(find(i));
    if(pars.size()==1)
    {
        printf("-1\n");
        return;
    }
    int prvi=*pars.begin();
    for(int i=0;i<n;i++)
    {
        if(find(i)==prvi)
            sets[i]=1;
        else
            sets[i]=2;
    }
    for(int i=0;i<n;i++)
        printf("%i ",sets[i]);
    printf("\n");
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
        test();
    return 0;
}