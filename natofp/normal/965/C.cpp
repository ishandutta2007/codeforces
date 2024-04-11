#include <iostream>

using namespace std;

unsigned long long int n,k,m,d;

unsigned long long int check(unsigned long long int i)
{
   unsigned long long int xmin,xmax,t;
   xmin=k/i;
   xmin/=n;
   t=xmax;
   t=k/n;
   if(i>1) t/=(i-1);
   if(t==0) return 0;
   else xmax=k/((i-1)*n+1);
   xmax=min(m,xmax);
   return xmax*i;



}

int main()
{

    cin>>k>>n>>m>>d;
    unsigned long long int ans=0;
    for(long long int i=1;i<=d;i++)
    {
        ans=max(ans,check(i));
    }
    cout<<ans;
    return 0;
}