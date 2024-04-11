#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

bool t[2][55][55][30];
bool calced[2][55][55][30];
vector<pair<int,int> > g[30];
string S[2];
int s[2][55];
int dp[55][55];
int n,m;
const int INF=1<<29;

void readgraf(){
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        char c1,c2,c3;
        scanf(" %c - > %c %c ",&c1,&c2,&c3);
        g[c1-'a'].pb(mp(c2-'a',c3-'a')); 
    }
}

bool calccan(int num,int l,int r,int k){
    if (calced[num][l][r][k]) return t[num][l][r][k];
    calced[num][l][r][k]=true;
    bool& ans=t[num][l][r][k];
    if (l==r-1 && s[num][l]==k) return ans=1;
    if (l>=r-1) return ans=0;
    for (int i=0;i<g[k].size() && !ans;i++){
        for (int j=l;j<=r && !ans;j++)
            if (calccan(num,l,j,g[k][i].first) && calccan(num,j,r,g[k][i].second))
                ans=true;
    }
//  if (k==2)       fprintf(stderr,"can[%d][%d][%d][%d] = %d\n",num,l,r,k,int(ans));
    return ans;
}

int calcdp(int r1,int r2){
    int& ans=dp[r1][r2];
    if (r1==0 && r2==0) return ans=0;
    if (ans!=-1) return ans;
//  fprintf(stderr,"DP[%d][%d] = \?\n",r1,r2);
    ans=INF;
    for (int c=0;c<26;c++){
        for (int i=1;i<=r1;i++)
            for (int j=1;j<=r2;j++)
                if (calccan(0,r1-i,r1,c) && calccan(1,r2-j,r2,c))
                    ans=min(ans,calcdp(r1-i,r2-j)+1);
    }
//  fprintf(stderr,"DP[%d][%d] = %d\n",r1,r2,ans);
    return ans;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>S[0]>>S[1];
    readgraf();
    n=S[0].size();
    m=S[1].size();
    for (int i=0;i<n;i++)
        s[0][i]=S[0][i]-'a';
    for (int i=0;i<m;i++)
        s[1][i]=S[1][i]-'a';
//  cerr<<calccan(0,0,1,0)<<endl;
    memset(dp,-1,sizeof(dp));
    int tmp=calcdp(n,m);    
    if (tmp<INF)
        cout<<tmp<<endl;
    else
        cout<<-1<<endl;
    return 0;
}