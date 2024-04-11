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
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=3e5+5;
vector<vector<int> > graf(N);
vector<int> sta(N);
int cnt(int tr,int par)
{
    if(graf[tr].size()==1&&tr!=0)
        return 1;
    if(sta[tr]==1)
    {
        int sol=INT_MAX;
        for(auto p:graf[tr])
        {
            if(p==par)
                continue;
            sol=min(sol,cnt(p,tr));
        }
        return sol;
    }
    else
    {
        int sol=0;
        for(auto p:graf[tr])
        {
            if(p==par)
                continue;
            sol+=cnt(p,tr);
        }
        return sol;
    }
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%i",&sta[i]);
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        graf[i].pb(a);
        graf[a].pb(i);
    }
    int leafs=0;
    for(int i=1;i<n;i++)
        if(graf[i].size()==1)
            leafs++;
    int a=cnt(0,-1);
    printf("%i\n",leafs-a+1);
    return 0;
}