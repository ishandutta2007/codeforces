#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    int arr[q];
    int size = 0;
    double mean =0;
    int max;
    int j=0;
    for(int i=0;i<q;i++)
    {
      int type;
      cin>>type;
      if(type==1)
      {
         cin>>arr[size];
         size++;
      }
      else
      {
         if(size == 1)
         {
            cout<<"0"<<endl;
            continue;
         }
         if(j!=0)
            mean = (mean*(j+1) - ((double)max) + ((double)arr[size-1]))/(j+1);
         else
            mean = (double)arr[size-1];
         max = arr[size-1];
         while(double(arr[j])<mean)
         {
            mean = (mean*(j+1) + ((double)arr[j]))/(j+2);
            j++;
         }
         cout<<setprecision(10)<<((double)max)-mean<<endl;
      }
    }
    return 0;
}