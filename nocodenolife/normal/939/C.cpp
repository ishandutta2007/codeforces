#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[2*n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      arr[i+n] = arr[i];
    }
    arr[0] = arr[n];
    int start,end;
    cin>>start>>end;
    int req = end - start;

    long long sum=0;
    for(int i=1;i<=req;i++)
    {
      sum+= arr[i];
    }

    long long summax = sum;
    int tim = start;
    int mintime = tim;
    //cout<<sum<<endl;

    for(int i=2;i<=n;i++)
    {
      tim--;
      if(tim==0)
         tim = n;
      sum-= arr[i-1];
      sum+= arr[i-1+req];
      //cout<<sum<<endl;
      if(sum>summax)
      {
         summax = sum;
         mintime = tim;
      }
      else if(sum == summax)
      {
         if(mintime>tim)
            mintime = tim;
      }
    }
    cout<<mintime<<endl;
    return 0;
}