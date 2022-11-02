// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y);
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z);
#define RS(x) scanf("%s",x);
#define PI(x) printf("%d\n",x);
#define PIS(x) printf("%d ",x);
#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef long long LL;
// }}}

char in[110][110];
int dir[110][110][4];
char r[1100];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int m,n;
inline bool emp(int i,int j){
    return i>=0&&i<n&&j>=0&&j<m&&in[i][j]!='#';
}
int main(){
    int k;
    RIII(n,m,k);
    REP(i,n)scanf("%s",in[i]);
    REP(i,n)REP(j,m){
        if(in[i][j]=='#')continue;
        if(in[i][j]>='0'&&in[i][j]<='9'){
            dir[i][j][0]=dir[i][j-1][0];
            dir[i][j][1]=dir[i-1][j][1];
        }else dir[i][j][0]=dir[i][j][1]=in[i][j];
    }
    PER(i,n)PER(j,m){
        if(in[i][j]=='#')continue;
        if(in[i][j]>='0'&&in[i][j]<='9'){
            dir[i][j][2]=dir[i][j+1][2];
            dir[i][j][3]=dir[i+1][j][3];
        }else dir[i][j][2]=dir[i][j][3]=in[i][j];
    }
    int sx,sy,ex,ey;
    RII(sx,sy);sx--;sy--;
    scanf("%s",r);
    RII(ex,ey);ex--;ey--;
    int p=0;
    while(k>0&&(r[p]||sx!=ex||sy!=ey)){
        //printf("sx=%d sy=%d p=%d k=%d\n",sx,sy,p,k);
        if(in[sx][sy]>='0'&&in[sx][sy]<='9'){
            k-=in[sx][sy]-'0';
            if(k<0)break;
        }else{
            k--;
        }
        if(r[p]){
            if(in[sx][sy]>='0'&&in[sx][sy]<='9'){
                REP(i,4){
                    if(dir[sx][sy][i]==r[p]){
                        sx+=dx[i];sy+=dy[i];
                        break;
                    }
                }
            }else{
                REP(i,4){
                    //printf("i=%d %d %d '%c'\n",i,sx+dx[i],sy+dy[i],dir[sx+dx[i]][sy+dy[i]][i]);
                    if(emp(sx+dx[i],sy+dy[i])&&dir[sx+dx[i]][sy+dy[i]][i]==r[p]){
                        sx+=dx[i];sy+=dy[i];
                        break;
                    }
                }
            }
            if(in[sx][sy]>='a'&&in[sx][sy]<='z')p++;
        }else{
            if(sx>ex)sx--;
            else if(sx<ex)sx++;
            else if(sy>ey)sy--;
            else sy++;
        }
    }
    printf("%d %d\n",sx+1,sy+1);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread