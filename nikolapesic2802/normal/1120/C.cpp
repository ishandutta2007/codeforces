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

const int N=5e3+5;
int dp[N],moze[N][N];
int n,a,b;
int calc(int pos)
{
    if(pos==n)
        return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    dp[pos]=a+calc(pos+1);
    for(int i=pos;i<n;i++)
        if(moze[pos][i])
            dp[pos]=min(dp[pos],b+calc(i+1));
    return dp[pos];
}
vector<int> Z(2*N);
void genZ(string s)
{
    int R=0,L=0;
    for(int i=1;i<s.size();i++)
    {
        if(R<i)
        {
            L=i,R=i;
            while(R<s.size()&&s[R]==s[R-L])
                R++;
            Z[i]=R-L;
            R--;
        }
        else
        {
            int K=i-L,O=R-i+1;
            if(Z[K]<O)
            {
                Z[i]=Z[K];
            }
            else
            {
                L=i;
                R++;
                while(R<s.size()&&s[R]==s[R-L])
                    R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
	scanf("%i %i %i",&n,&a,&b);
	string s;
	cin >> s;
    for(int i=0;i<n;i++)
    {
        int b=n-i+1;
        genZ(s.substr(i,n-i)+'$'+s);
        for(int j=1;j<n;j++)
        {
            int m=min(Z[j+b],j-i);
            m=max(m,0);
            while(m--)
                if(moze[j][j+m])
                    break;
                else
                    moze[j][j+m]=1;
        }
    }
    printf("%i\n",calc(0));
    return 0;
}