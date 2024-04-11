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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

int g[100][100];
int n;
int l1,r1,l2,r2;
int64 t[52][52];
int64 t1[52][52];

bool better(const pair<int,int>& a,const pair<int,int>& b){
    if (a.first!=b.first)
        return a.first<b.first;
    return a.second<b.second;
}

int64 solve(int w,int l){
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            t[i][j]=0;
    t[0][0]=1;
/*  int cntg,cntl,cnt;
    cnt=cntg=cntl=0;
    for (int i=0;i<n;i++){
        if ((better(mp(g[i][0],i),mp(g[w][0],w)) || i==w) && i!=l)
            cntg++;
        if ((better(mp(g[l][n-1],l),mp(g[i][n-1],i)) || i==l) && i!=w )
            cntl++;
        if (better(mp(g[i][0],i),mp(g[w][0],w)) || better(mp(g[l][n-1],l),mp(g[i][n-1],i)) || i==w || i==l)
            cnt++;
    }
    if (n-cnt>r2 || cntg<l1 || cntl<(n-r2-r1))
        return 0;*/
//  cerr<<w<<" "<<l<<endl;
    for (int i=0;i<n;i++)
    {
        bool cg=((i!=l) && better(mp(g[i][0],i),mp(g[w][0],w))) || (i==w);
        bool cs=(i!=w) && (i!=l);
        if (cs){
            cs=false;
            for (int j=0;j<n-1 && !cs;j++)
                if (better(mp(g[w][0],w),mp(g[i][j],i)) && better(mp(g[i][j],i),mp(g[l][n-2],l)))
                    cs=true;
        }
        bool cl=(i!=w && better(mp(g[l][n-2],l),mp(g[i][n-2],i))) || (i==l);
        for (int g=0;g<=r1;g++)
            for (int s=0;s<=r2;s++)
                t1[g][s]=0;
    //  cerr<<cg<<" "<<cs<<" "<<cl<<endl;
        for (int g=0;g<=r1;g++)
            for (int s=0;s<=r2;s++){
                if (cg) t1[g+1][s]+=t[g][s];
                if (cs) t1[g][s+1]+=t[g][s];
                if (cl) t1[g][s]+=t[g][s];
            }
        for (int g=0;g<=r1;g++) 
            for (int s=0;s<=r2;s++)
                t[g][s]=t1[g][s];
    }
    int64 ans=0;
    for (int i=l1;i<=r1;i++)
        for (int j=l2;j<=r2;j++)
            ans+=t[i][j];
//  cerr<<l<<" "<<w<<" "<<ans<<endl;
//  cerr<<endl<<endl;
    return ans;     
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            g[i][j]=(1<<29)*(i!=j);
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        g[a][b]=min(g[a][b],c);
        g[b][a]=g[a][b];
    }
    scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for (int i=0;i<n;i++){
        swap(g[i][i],g[i][n-1]);
        sort(g[i],g[i]+n-1);
    }
    int64 ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j)
                ans+=solve(i,j);
    cout<<ans<<endl;
    return 0;
}