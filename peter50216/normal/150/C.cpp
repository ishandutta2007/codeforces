#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
double in[200000];
double p[200000],x[200000];
double nm[200000];
double ma[200000],mi[200000];
double st[200000],ed[200000];
double stma[200000],edmi[200000];
double tt[1100][1100];
double sc[1100][1100];
double ans[300010];
double qq[1100][1100];
int q1[300010],q2[300010];
int main(){
    int n,m,c,i,j,k;
    scanf("%d%d%d",&n,&m,&c);
    for(i=0;i<n;i++)scanf("%lf",&x[i]);
    p[0]=0;
    for(i=1;i<n;i++){
        double a;
        scanf("%lf",&a);
        p[i]=p[i-1]+a/100;
    }
    for(i=0;i<n;i++)in[i]=x[i]/2-c*p[i];
    int nn=sqrt(n+1);
    if(nn>n)nn=n;
    int nk=(n+nn-1)/nn;
    for(i=0;i<nk;i++){
        int q=i*nn,w=(i+1)*nn;
        if(w>n)w=n;
        nm[i]=-1e300;
        ma[i]=-1e300;
        mi[i]=1e300;
        for(j=q;j<w;j++){
            st[j]=-1e300;
            stma[j]=-1e300;
            ma[i]=max(ma[i],in[j]);
            mi[i]=min(mi[i],in[j]);
            for(k=q;k<=j;k++){
                stma[j]=max(stma[j],in[k]);
                st[j]=max(st[j],in[j]-in[k]);
            }
            if(j>q)st[j]=max(st[j],st[j-1]);
            nm[i]=max(nm[i],st[j]);
        }
        for(j=w-1;j>=q;j--){
            ed[j]=-1e300;
            edmi[j]=1e300;
            for(k=w-1;k>=j;k--){
                edmi[j]=min(edmi[j],in[k]);
                ed[j]=max(ed[j],in[k]-in[j]);
            }
            if(j<w-1)ed[j]=max(ed[j],ed[j+1]);
        }
    }
    for(i=0;i<nk;i++)for(j=i+1;j<nk;j++){
        tt[i][j]=ma[j]-mi[i];
    }
    for(i=2;i<nk;i++)for(j=0;j<nk-i;j++){
        tt[j][j+i]=max(tt[j][j+i],tt[j+1][j+i]);
        tt[j][j+i]=max(tt[j][j+i],tt[j][j+i-1]);
    }
    int ii;
    for(ii=0;ii<m;ii++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        q1[ii]=a;q2[ii]=b;
        int aid=a/nn;
        int bid=b/nn;
        if(aid==bid){
            ans[ii]=-1;
        }else{
            //if(n==1000){
            //    printf("%d %d %lf\n",a,b,in[b]);
           // }
            ans[ii]=max(ed[a],st[b]);
            for(i=aid+1;i<bid;i++)ans[ii]=max(ans[ii],nm[i]);
            if(aid+1<bid-1)ans[ii]=max(ans[ii],tt[aid+1][bid-1]);
            for(i=aid+1;i<bid;i++)ans[ii]=max(ans[ii],ma[i]-edmi[a]);
            ans[ii]=max(ans[ii],stma[b]-edmi[a]);
            for(i=aid+1;i<bid;i++)ans[ii]=max(ans[ii],stma[b]-mi[i]);
            /*if(n==1000){
                double a2=-1e100,iii,jjj;
                for(i=a;i<=b;i++){
                    for(j=i;j<=b;j++){
                        if(in[j]-in[i]>a2){
                            a2=in[j]-in[i];iii=i;jjj=j;
                        }
                    }
                }
                printf("ans=%lf %lf %d %d\n",ans[ii],a2,iii,jjj);
            }*/
        }
    }
    for(i=0;i<nk;i++){
        int q=i*nn,w=(i+1)*nn;
        if(w>n)w=n;
        for(j=q;j<w;j++){
            for(k=j;k<w;k++){
                qq[j-q][k-q]=in[k]-in[j];
            }
        }
        for(j=1;j<w-q;j++){
            for(k=q;k<w-j;k++){
                qq[k-q][k+j-q]=max(qq[k-q][k+j-q],qq[k-q+1][k+j-q]);
                qq[k-q][k+j-q]=max(qq[k-q][k+j-q],qq[k-q][k+j-q-1]);
            }
        }
        for(j=0;j<m;j++){
            if(ans[j]<0&&q1[j]/nn==i){
                ans[j]=qq[q1[j]-q][q2[j]-q];
            }
        }
    }
    double t=0;
    for(i=0;i<m;i++){
        if(ans[i]<0)while(1);
        //printf("%.9lf\n",ans[i]);
        t+=ans[i];
    }
    printf("%.9lf\n",t);
}