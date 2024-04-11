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

const int N=501,L=251;
ll dp[2][N][L][2];
ll val[N][N],sub[L][2];
vector<pair<int,int> > rem[N][N][2];
vector<int> dx={0,1,1,0},dy={0,-1,0,1};
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=0;i<k;i++){
        int x,y,d,t,e;
        scanf("%i %i %i %i %i",&x,&y,&d,&t,&e);
        vector<bool> moze(4);
        for(int o=0;o<4;o++){
            int xx=x+dx[o]*d,yy=y+dy[o]*d;
            if((xx+yy)%4!=(t+o)%4||t>xx+yy)
                continue;
            moze[o]=1;
            val[xx][yy]+=e;
            if(o==2&&moze[0])
                rem[xx][yy][0].pb({d,e});
            if((o==2&&moze[1])||(o==3&&moze[0]))
                rem[xx][yy][1].pb({d,e});
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            sort(all(rem[i][j][0])),sort(all(rem[i][j][1]));
    for(int i=0;i<2;i++)
        for(int j=0;j<m;j++)
            for(int l=0;l<L;l++)
                dp[i][j][l][0]=dp[i][j][l][1]=LLONG_MAX/2;
    dp[0][0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            for(int l=0;l<L;l++)
                dp[i&1^1][j][l][0]=dp[i&1^1][j][l][1]=LLONG_MAX/2;
        for(int j=0;j<m;j++){
            for(int o=0;o<2;o++){
                sub[0][o]=0;
                int it=0;
                for(int l=1;l<L;l++)
                {
                    sub[l][o]=sub[l-1][o];
                    while(it<rem[i][j][o].size()&&rem[i][j][o][it].f==l)
                        sub[l][o]+=rem[i][j][o][it].s,it++;
                }
            }
            for(int l=0;l<L;l++)
                for(int o=0;o<2;o++)
                {
                    dp[i&1][j][l][o]+=val[i][j]-sub[l][o];
                    if(o)
                        dp[i&1][j+1][min(l+1,L-1)][1]=min(dp[i&1][j+1][min(l+1,L-1)][1],dp[i&1][j][l][o]),dp[i&1^1][j][1][0]=min(dp[i&1^1][j][1][0],dp[i&1][j][l][o]);
                    else
                        dp[i&1][j+1][1][1]=min(dp[i&1][j+1][1][1],dp[i&1][j][l][o]),dp[i&1^1][j][min(l+1,L-1)][0]=min(dp[i&1^1][j][min(l+1,L-1)][0],dp[i&1][j][l][o]);
                }
        }
    }
    ll sol=LLONG_MAX;
    for(int l=0;l<L;l++)
        sol=min({sol,dp[(n-1)&1][m-1][l][0],dp[(n-1)&1][m-1][l][1]});
    printf("%lld\n",sol);
    return 0;
}