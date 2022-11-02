#include<stdio.h>
#include<algorithm>
using namespace std;
int in[110];
int main(){
   int n,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)scanf("%d",&in[i]);
   sort(in,in+n);
   int c=0,s=0;
   int cc=0;
   for(i=0;i<n;i++){
      if(in[i]+s>710)break;
      c++;
      s+=in[i];
      if(s<=350)cc+=0;
      else cc+=s-350;
   }
   printf("%d %d\n",c,cc);
}