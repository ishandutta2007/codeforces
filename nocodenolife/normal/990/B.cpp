#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int value[n];
    for(int i=0;i<n;i++)
    {
      value[i]=1;
   }
    sort(arr, arr+n);

    int answer = n;
    for(int i=0;i<n-1;i++)
    {
      if(arr[i] == arr[i+1])
      {
         value[i+1] += value[i];
         continue;
      }

      if((arr[i]+k >= arr[i+1]))
         answer-= value[i];
   }

   cout<<answer<<endl;

    return 0;
}