#include <cstdio>

int main(){
    int n,k,i,x;
    double l,v1,v2,t,s;
    scanf("%d%lf%lf%lf%d" ,&n,&l,&v1,&v2,&k);
    t=0;
    if(v1>=v2)
       t=l/v1;
    else{
       t=0;
       s=0;
       if(n%k==0)
         x=2*(n/k)-1;
       else
         x=2*(n/k)+1;
       while(x>0){
          if(x%2==1)
            s=s+1/(v2-v1);
          else
            s=s+1/(v2+v1);
          x--;
       }
       t=l*s/(1+v1*s);
    }
    printf("%.10lf" ,t);
    return 0;
}