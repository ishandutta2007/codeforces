#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=510;
const int MOD=998244353;
vector<int>ansp;
bool del[N<<1];
int b[N][N],a[N<<1][N],n;
void dele(int x)
{
    del[x]=1;
    rep(i,2*n)if(!del[i])rep(j,n)if(a[i][j]==a[x][j]){del[i]=1;break;}
}
int main()
{
    int T;
    scanf("%d",&T);
    rep(Tim,T)
    {
        scanf("%d",&n);
        rep(i,2*n)rep(j,n)scanf("%d",&a[i][j]);
        rep(i,2*n)del[i]=0;
        int ans=1;ansp.clear();
        for(;;)
        {
            rep(i,n)rep(j,n)b[i][j]=0;
            rep(i,2*n)if(!del[i])rep(j,n)b[j][a[i][j]]++;
            bool flag=0;
            rep(i,2*n)if(!del[i])
            {
                int pos=-1;
                rep(j,n)if(b[j][a[i][j]]==1){pos=j;break;}
                if(pos!=-1)
                {
                    dele(i);
                    ansp.pb(i);
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            int pos=-1;
            rep(i,2*n)if(!del[i]){pos=i;break;}
            if(pos==-1)break;
            ans=(ans<<1)%MOD;
            dele(pos);
            ansp.pb(pos);
        }
        assert(ansp.size()==n);
        printf("%d\n",ans);
        rep(i,n)printf("%d%c",ansp[i-1]," \n"[i==n]);
    }
    return 0;
}