#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
typedef long long ll;
int n,m,i,j,k,t,t1,a[200001],dp[200001], sum[200001],nxt[200001],used[200001],aad,bad;
vector<int> gt[200001],revgt[200001];
deque<int> bruh;
void proc(int x)
{
//    cout<<"proc "<<x<<endl;
    for (int i=0;i<revgt[x].size();i++) if (!dp[revgt[x][i]]) {
        dp[revgt[x][i]]=dp[x]+1; 
        bruh.push_back(revgt[x][i]);
    }
}
int main(){
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>aad>>bad;
        gt[aad].push_back(bad);
        revgt[bad].push_back(aad);
    }
    cin>>k;
    for (i=0;i<k;i++) cin>>a[i];
    bruh.push_back(a[k-1]);
    dp[a[k-1]]=1;
    while(bruh.size())
    {
        proc(bruh.front());
        bruh.pop_front();
    }
 //   for (i=1;i<=n;i++) cout<<dp[i]<<' ';
 //   cout<<endl;
    aad=0; bad=0;
    for (i=0;i<k-1;i++)
    {
        int x=a[i],minn=1e9;
 //       cout<<x<<' '<<gt[x].size()<<endl;
        for (j=0;j<gt[x].size();j++)
        {
            minn=min(minn,dp[gt[x][j]]);
        }
  //      cout<<minn<<endl;
            if (dp[a[i+1]]>minn) {aad++; bad++;}
            else
            {
                int fail=0;
        for (j=0;j<gt[x].size();j++) if (minn==dp[gt[x][j]]) {fail++;}
            if (fail>=2) bad++;
 //           cout<<fail<<endl;
            }
    }
    cout<<aad<<' '<<bad;
}