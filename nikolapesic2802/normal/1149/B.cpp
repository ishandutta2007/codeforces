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

const int N=255;
int dp[N][N][N];
int nxt[(int)1e5+5][26];
vector<vector<int> > words(3);
int calc(int a,int b,int c)
{
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    dp[a][b][c]=INT_MAX;
    if(a>0)
    {
        int tr=calc(a-1,b,c);
        if(tr!=INT_MAX)
            if(nxt[tr][words[0][a-1]]!=-1)
                dp[a][b][c]=min(dp[a][b][c],nxt[tr][words[0][a-1]]);
    }
    if(b>0)
    {
        int tr=calc(a,b-1,c);
        if(tr!=INT_MAX)
            if(nxt[tr][words[1][b-1]]!=-1)
                dp[a][b][c]=min(dp[a][b][c],nxt[tr][words[1][b-1]]);
    }
    if(c>0)
    {
        int tr=calc(a,b,c-1);
        if(tr!=INT_MAX)
            if(nxt[tr][words[2][c-1]]!=-1)
                dp[a][b][c]=min(dp[a][b][c],nxt[tr][words[2][c-1]]);
    }
    return dp[a][b][c];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                dp[i][j][k]=-1;
    dp[0][0][0]=0;
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	s='a'+s;
	n++;
	vector<int> last(26,-1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            nxt[i][j]=last[j];
        last[s[i]-'a']=i;
    }
    while(q--)
    {
        int x;
        string s;
        cin >> s >> x;
        x--;
        if(s[0]=='+')
        {
            string c;
            cin >> c;
            words[x].pb(c[0]-'a');
        }
        else
        {
            int s=words[x].size();
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                {
                    if(x==0)
                        dp[s][i][j]=-1;
                    if(x==1)
                        dp[i][s][j]=-1;
                    if(x==2)
                        dp[i][j][s]=-1;
                }
            words[x].pop_back();
        }
        if(calc(words[0].size(),words[1].size(),words[2].size())==INT_MAX)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}