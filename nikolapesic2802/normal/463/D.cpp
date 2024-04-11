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
int n;
vector<vector<bool> > graf;
vector<int> sol;
int calc(int i)
{
    if(sol[i]!=-1)
        return sol[i];
    sol[i]=0;
    for(int j=0;j<n;j++)
        if(graf[i][j])
            sol[i]=max(sol[i],calc(j));
    sol[i]++;
    return sol[i];
}
int main()
{
	int k;
	scanf("%i %i",&n,&k);
	graf.resize(n,vector<bool>(n,1));sol.resize(n,-1);
	for(int i=0;i<k;i++)
    {
        vector<vector<bool> >moze(n,vector<bool> (n));
        vector<int> seq(n);
        for(int i=0;i<n;i++)
            scanf("%i",&seq[i]),seq[i]--;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                moze[seq[i]][seq[j]]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                graf[i][j]=graf[i][j]&moze[i][j];
    }
    for(int i=0;i<n;i++)
        if(sol[i]==-1)
            calc(i);
    int m=0;
    for(int i=0;i<n;i++)
        m=max(m,sol[i]);
    printf("%i\n",m);
    return 0;
}