#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=152,oo=INT_MAX/2;
int dp[2][N][N*N/4]; //Num,uzeto,potroseno
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k,s;
	scanf("%i %i %i",&n,&k,&s);
	auto getbind=[&](int x,int i){
        return x*(i-x);
	};
	s=min(s,getbind(k,n));
	vector<int> q(n);
	for(int i=0;i<n;i++)
        scanf("%i",&q[i]);
    for(int i=0;i<=k;i++)
        for(int j=0;j<=s;j++)
            dp[0][i][j]=oo;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=min(i+1,k);j++)
            for(int p=0;p<=getbind(j,i+1);p++)
                dp[i&1^1][j][p]=oo;
        for(int j=0;j<=min(i,k);j++)
            for(int p=0;p<=getbind(j,i);p++)
                dp[i&1^1][j][p]=min(dp[i&1^1][j][p],dp[i&1][j][p]),dp[i&1^1][j+1][p+i-j]=min(dp[i&1^1][j+1][p+i-j],dp[i&1][j][p]+q[i]);
    }
    int sol=oo;
    for(int i=0;i<=s;i++)
        sol=min(sol,dp[n&1][k][i]);
    printf("%i\n",sol);
    return 0;
}