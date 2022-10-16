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

int n,m;
const int N=2005;
vector<int> a(N,-1);
int dp[N][N];
int calc(int pos,int remain)
{
    if(remain<0||pos>n)
        return INT_MIN/10;
    if(a[pos]==-1&&remain==0)
        return 0;
    if(dp[pos][remain]!=-1)
        return dp[pos][remain];
    dp[pos][remain]=INT_MIN/10;
    if(a[pos]!=-1)
        dp[pos][remain]=max(dp[pos][remain],calc(a[pos]+1,remain-(a[pos]-pos+1-m))+1);
    dp[pos][remain]=max(dp[pos][remain],calc(pos+1,remain-1));
    dp[pos][remain]=max(dp[pos][remain],calc(pos+1,remain));
    return dp[pos][remain];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	string s,p;
	cin >> s >> p;
	n=s.size();m=p.size();
	vector<vector<int> > nxt(n,vector<int>(26));
	vector<int> gde(26,-1);
	for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            nxt[i][j]=gde[j];
        gde[s[i]-'a']=i;
    }
    for(int i=0;i<n;i++)
    {
        int tr=0;
        int sol=-1;
        if(s[i]==p[0])
            tr++,sol=i;
        int pos=i;
        while(tr<m)
        {
            if(nxt[pos][p[tr]-'a']==-1)
            {
                sol=-1;
                break;
            }
            else
            {
                pos=nxt[pos][p[tr]-'a'];
                sol=pos;
                tr++;
            }
        }
        a[i]=sol;
    }
    for(int i=0;i<=n;i++)
        printf("%i ",calc(0,i));
    return 0;
}