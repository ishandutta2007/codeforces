#include <bits/stdc++.h>
#define MAXN 70000
#define INF 1000000000000LL
const double EPS=0.0000001;
double x[MAXN+1];
double v[MAXN+1];
int n;
inline bool check(double t){
   double l,r;
   l=-INF;
   r=INF;
   for(int i=1;i<=n;i++){
      if(std::max(l,x[i]-t*v[i])>std::min(r,x[i]+t*v[i]))
          return 0;
      l=std::max(l,x[i]-t*v[i]);
      r=std::min(r,x[i]+t*v[i]);
   }
   return 1;
}
int main(){
    FILE*fi,*fout;
    int i;
    double rez,pas;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
        fscanf(fi,"%lf" ,&x[i]);
    for(i=1;i<=n;i++)
        fscanf(fi,"%lf" ,&v[i]);
    rez=0;
    pas=1.0;
    for(i=1;i<=30;i++)
          pas*=2.0;
    for(;pas>EPS;pas/=2)
      if(check(rez+pas)==0)
        rez+=pas;
    while(check(rez)==0)
        rez+=EPS;
    fprintf(fout,"%.12lf" ,rez);
   // fclose(fi);
    //fclose(fout);
    return 0;
}