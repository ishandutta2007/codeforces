#include <bits/stdc++.h>
using namespace std;


long long int min(long long int v, long long int w)
{
   if(v>w)
      return w;
   return v;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m,k;
    cin>>n>>m>>k;

    long long int arr[n] = {0};
    for(long long int i=0;i<m;i++)
    {
      long long int l;
      cin>>l;
      arr[l] = 1;
    }
    if(arr[0]==1)
    {
      cout<<"-1"<<endl;
      return 0;
   }

   long long int pi=0;
   long long int pos[n];
   for(long long int i=1;i<n;i++)
   {
     if(arr[i]==1)
     {
      pos[i]=pi;
     }
     else
      pi=i;
   }
    long long int answer = -1;
    long long int ans=0;
    for(long long int i=1;i<=k;i++)
    {
      long long int cost;
      cin>>cost;

      long long int number = 0;
      long long int x = 0;
      long long int prev = -1;
      long long int flag = 1;
      while(x<n)
      {

         if(arr[x]==0)
         {
            prev = x;
            number++;
            x+=i;
         }
         else if(arr[x]==1)
         {
            x = pos[x];
            if(x<=prev)
            {
               flag = 0;
               break;
            }
            else
            {
               number++;
               prev = x;
               x=x+i;
            }
         }
      }
      if(flag == 1)
      {
         ans=1;
         if(answer==-1)
            answer = cost*number;
         answer = min(cost*number,answer);
      }
    }
    if(ans==1)
      cout<<answer<<endl;
   else
      cout<<"-1"<<endl;
    return 0;
}