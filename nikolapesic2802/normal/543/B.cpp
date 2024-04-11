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

const int N=3001;
vector<vector<int> > graf(N);
int n,m,a,b,s1,t1,l1,s2,t2,l2;
vector<vector<int> > dist(N,vector<int>(N,N));
int main()
{

	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
        scanf("%i %i",&a,&b),a--,b--,graf[a].pb(b),graf[b].pb(a);
    scanf("%i %i %i %i %i %i",&s1,&t1,&l1,&s2,&t2,&l2);
    s1--;t1--;s2--;t2--;
    for(int i=0;i<N;i++)
    {
        dist[i][i]=0;
        queue<int> q;
        q.push(i);
        while(q.size())
        {
            int tr=q.front();
            q.pop();
            for(auto p:graf[tr])
                if(dist[i][p]==N)
                    dist[i][p]=dist[i][tr]+1,q.push(p);
        }
    }
    int sol=INT_MAX;
    if(dist[s1][t1]<=l1&&dist[s2][t2]<=l2)
        sol=dist[s1][t1]+dist[s2][t2];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int d1=dist[s1][i]+dist[i][j]+dist[j][t1],d2=dist[s2][i]+dist[i][j]+dist[j][t2];
            if(d1<=l1&&d2<=l2)
                sol=min(sol,d1+d2-dist[i][j]);
        }
    swap(s1,t1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int d1=dist[s1][i]+dist[i][j]+dist[j][t1],d2=dist[s2][i]+dist[i][j]+dist[j][t2];
            if(d1<=l1&&d2<=l2)
                sol=min(sol,d1+d2-dist[i][j]);
        }
    if(sol==INT_MAX)
        printf("-1\n");
    else
        printf("%i\n",m-sol);
    return 0;
}