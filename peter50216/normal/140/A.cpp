#include<stdio.h>
#include<math.h>
int n;
double a,b;
const double eps = 1e-7;
inline bool solve(){
   if(a+eps<=b)return 0;
   else if(a+eps<2*b){
      if(n==1)return 1;
      return 0;
   }
   double th=asin(b/(a-b))*2;
   const double pi=acos(-1);
   return th*n<=2*pi+eps;
}
int main(){
   scanf("%d%lf%lf",&n,&a,&b);
   puts(solve()?"YES":"NO");
}