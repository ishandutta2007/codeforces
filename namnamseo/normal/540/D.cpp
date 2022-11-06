#include <cstdio>

double dp[101][101][101];
bool chk[101][101][101];

double prob(int r,int s,int p){
    if(r==0) return 0;
    if(s+p==0) return 1;
    if(chk[r][s][p]) return dp[r][s][p];
    chk[r][s][p]=true;
    double tmp=0;
    if(r && s) tmp+=prob(r,s-1,p)/(r*s+s*p+p*r)*(r*s);
    if(s && p) tmp+=prob(r,s,p-1)/(r*s+s*p+p*r)*(p*s);
    if(p && r) tmp+=prob(r-1,s,p)/(r*s+s*p+p*r)*(r*p);
    return dp[r][s][p]=tmp;
}

int main()
{
    int r,s,p;
    scanf("%d%d%d",&r,&s,&p);
    printf("%.9lf %.9lf %.9lf",
           prob(r,s,p),
           prob(s,p,r),
           prob(p,r,s));
    return 0;
}