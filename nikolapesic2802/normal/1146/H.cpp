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

struct pt{
    int x,y;
    pt operator-(pt a){return {x-a.x,y-a.y};}
};
const int N=301;
ll dp[N][N][6];
int main()
{
	int n;
	scanf("%i",&n);
	vector<pt> p(n);
	for(int i=0;i<n;i++)
        scanf("%i %i",&p[i].x,&p[i].y);
    vector<pair<double,pair<int,int> > > s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            pt a=p[j]-p[i];
            s.pb({atan2(a.y,a.x),{i,j}});
        }
    }
    sort(all(s));
    for(int i=0;i<n;i++)
        dp[i][i][0]=1;
    for(auto p:s)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<5;k++)
                dp[j][p.s.s][k+1]+=dp[j][p.s.f][k];
        }
    }
    ll total=0;
    for(int i=0;i<n;i++)
        total+=dp[i][i][5];
    printf("%lld\n",total);
    return 0;
}