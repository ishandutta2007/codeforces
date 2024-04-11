#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
      int n,n1;
      cin>>n;
      if(n<10)
      printf("1");
      else 
      {
        int i=1;
        while(i<=n)
        {
            i*=10;
        }
         i/=10;
         if(n%i==0)
         {
            printf("%d",i);
          } 
          else 
          printf("%d",(n/i+1)*i-n);
      }
    return 0; 
}