#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second
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

const int N=25,M=24*50*1000+1;
bitset<M> dp[2*N-1][N];
int ans[2][N];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	vector<int> vals(2*n);
	for(int i=0;i<2*n;i++)
        scanf("%i",&vals[i]);
    sort(vals.rbegin(),vals.rend());
    ans[0][0]=vals[2*n-1];
    ans[1][n-1]=vals[2*n-2];
    vector<int> cnt(50*1000+1);
    int sum=0;
    for(int i=0;i<2*n-2;i++)
        sum+=vals[i],cnt[vals[i]]++;
    int m=2*n-2;
    dp[m][0][0]=1;
    for(int i=m;i>0;i--)
        for(int j=0;j<n;j++)
            for(int s=0;s<M;s++)
                if(dp[i][j][s])
                {
                    dp[i-1][j][s]=1;
                    if(j!=n-1)
                        dp[i-1][j+1][s+vals[i-1]]=1;
                }
    int an=M,st=0;
    for(int s=0;s<M;s++)
        if(dp[0][n-1][s])
        {
            int tr=max(s,sum-s);
            if(tr<an)
                an=tr,st=s;
        }
    int j=n-1,s=st,tr=n-1;
    for(int i=1;i<=m;i++)
    {
        if(dp[i][j][s])
            continue;
        j--;
        s-=vals[i-1];
        ans[0][tr--]=vals[i-1];
        cnt[vals[i-1]]--;
    }
    tr=0;
    for(int i=50*1000;i>=0;i--)
        while(cnt[i])
            ans[1][tr++]=i,cnt[i]--;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)
            printf("%i ",ans[i][j]);
        printf("\n");
    }
    return 0;
}