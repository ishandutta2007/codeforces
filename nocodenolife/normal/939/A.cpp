#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
      if(arr[arr[arr[i]]] == i)
      {
         cout<<"YES"<<endl;
         return 0;
      }
    }

    cout<<"NO"<<endl;

    return 0;
}