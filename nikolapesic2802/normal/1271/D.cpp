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

const int N=5001;
vector<int> a(N),b(N),c(N);
vector<vector<int> > graf(N);
int dp[N][N],n,m,k;
int calc(int tr,int s){
    if(s<0)
        return -N*N;
    if(tr==n)
        return 0;
    if(dp[tr][s]!=-1)
        return dp[tr][s];
    if(s<a[tr])
        return dp[tr][s]=-N*N;
    s+=b[tr];
    dp[tr][s-b[tr]]=calc(tr+1,s);
    for(int i=0;i<graf[tr].size();i++){
        dp[tr][s-b[tr]]=max(dp[tr][s-b[tr]],calc(tr+1,s-i-1)+graf[tr][i]);
    }
    return dp[tr][s-b[tr]];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i %i %i",&n,&m,&k);
	for(int i=0;i<n;i++)
        scanf("%i %i %i",&a[i],&b[i],&c[i]);
    vector<int> mx(n);
    for(int i=0;i<n;i++)
        mx[i]=i;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%i %i",&u,&v);
        u--;v--;
        mx[v]=max(mx[v],u);
    }
    for(int i=0;i<n;i++)
        graf[mx[i]].pb(c[i]);
    for(int i=0;i<n;i++){
        sort(all(graf[i]));
        reverse(all(graf[i]));
        for(int j=1;j<graf[i].size();j++)
            graf[i][j]+=graf[i][j-1];
    }
    int sol=calc(0,k);
    if(sol<0){
        printf("-1\n");
        return 0;
    }
    printf("%i\n",calc(0,k));
    return 0;
}