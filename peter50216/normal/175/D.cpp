#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
double dp[210][210][2][31];
double dpx[210][210][2][31];
double dpy[210][210][2][31];
int h1,dt1,l1,r1,p1;double pp1;
int h2,dt2,l2,r2,p2;double pp2;
inline int gcd(int a,int b){if(b)while((a%=b)&&(b%=a));return a+b;}
int mt;
double add[2][31];
int nex[2][31][2];
bool u[2][31];
int st[100][2];
double rem[101];
double rem2[101];
inline void dpf(int hx,int hy){
    int i,j;
    if(hy==0){
        for(i=0;i<2;i++)for(j=0;j<=mt;j++){
            dp[hx][hy][i][j]=1;
        }
        return;
    }
    if(hx==0){
        for(i=0;i<2;i++)for(j=0;j<=mt;j++){
            dp[hx][hy][i][j]=0;
        }
        return;
    }
    memset(add,0,sizeof(add));
    int x;
    for(i=0;i<2;i++)for(j=0;j<=mt;j++){
        int ni,nj;
        int nt1,nt2;
        if(i==0)nt1=dt1,nt2=j;
        else nt1=j,nt2=dt2;
        if(nt1<=nt2){
            ni=0;nj=nt2-nt1;
        }else{
            ni=1;
            nj=nt1-nt2;
        }
        nex[i][j][0]=ni;
        nex[i][j][1]=nj;
        
        if(i==0){
            if(hy>r1){
                add[i][j]=(dpy[hx][hy-l1][ni][nj]-dpy[hx][hy-r1-1][ni][nj]);
            }else if(hy>=l1){
                add[i][j]=dpy[hx][hy-l1][ni][nj]+(r1-hy)*dp[hx][0][ni][nj];
            }else{
                add[i][j]=(r1-l1+1)*dp[hx][0][ni][nj];
            }
            add[i][j]=add[i][j]/(r1-l1+1)*(1-pp1);
        }else{
            if(hx>r2){
                add[i][j]=(dpx[hx-l2][hy][ni][nj]-dpx[hx-r2-1][hy][ni][nj]);
            }else if(hx>=l2){
                add[i][j]=dpx[hx-l2][hy][ni][nj]+(r2-hx)*dp[0][hy][ni][nj];
            }else{
                add[i][j]=(r2-l2+1)*dp[0][hy][ni][nj];
            }
            add[i][j]=add[i][j]/(r2-l2+1)*(1-pp2);
        }
        /*
        if(i==0){
            for(x=l1;x<=r1;x++){
                int hly=max(0,hy-x);
                add[i][j]+=dp[hx][hly][ni][nj]/(r1-l1+1)*(1-pp1);
            }
        }else{
            for(x=l2;x<=r2;x++){
                int hlx=max(0,hx-x);
                add[i][j]+=dp[hlx][hy][ni][nj]/(r2-l2+1)*(1-pp2);
            }
        }*/
        //printf("%d %d %d %d %lf\n",hx,hy,i,j,add[i][j]);
    }
    memset(u,0,sizeof(u));
    for(i=0;i<2;i++)for(j=0;j<mt;j++){
        if(u[i][j])continue;
        int ii=i,jj=j,ss=0;
        while(!u[ii][jj]){
            st[ss][0]=ii;st[ss][1]=jj;
            ss++;
            u[ii][jj]=1;
            int iii=ii,jjj=jj;
            ii=nex[iii][jjj][0];
            jj=nex[iii][jjj][1];
        }
        rem[ss-1]=add[st[ss-1][0]][st[ss-1][1]];
        int k;
        double nh=1;
        for(k=0;k<ss;k++)nh*=(st[k][0]==0?pp1:pp2);
        for(k=ss-2;k>=0;k--){
            rem[k]=rem[k+1]*(st[k][0]==0?pp1:pp2)+add[st[k][0]][st[k][1]];
        }
        rem2[0]=add[st[0][0]][st[0][1]];
        double pp=1;
        for(k=1;k<ss;k++){
            pp*=(st[k-1][0]==0?pp1:pp2);
            rem2[k]=rem2[k-1]+add[st[k][0]][st[k][1]]*pp;
        }
        pp=1;
        for(k=ss-1;k>=0;k--){
            pp*=(st[k][0]==0?pp1:pp2);
            dp[hx][hy][st[k][0]][st[k][1]]=((k>0?pp*rem2[k-1]:0)+rem[k])/(1-nh);
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&h1,&dt1,&l1,&r1,&p1);
    pp1=p1/100.0;
    scanf("%d%d%d%d%d",&h2,&dt2,&l2,&r2,&p2);
    pp2=p2/100.0;
    if(p1==100){
        puts("0.0000000000");
        return 0;
    }
    if(p2==100){
        puts("1.0000000000");
        return 0;
    }
    mt=max(dt1,dt2);
    int i,j,k,l;
//    dpf(1,1);
    for(i=0;i<=h1;i++)for(j=0;j<=h2;j++){
        dpf(i,j);
        for(k=0;k<2;k++)for(l=0;l<=mt;l++){
            if(i)dpx[i][j][k][l]=dpx[i-1][j][k][l]+dp[i][j][k][l];
            else dpx[i][j][k][l]=dp[i][j][k][l];
            if(j)dpy[i][j][k][l]=dpy[i][j-1][k][l]+dp[i][j][k][l];
            else dpy[i][j][k][l]=dp[i][j][k][l];
        }
    }
    printf("%.10lf\n",dp[h1][h2][0][0]);
}