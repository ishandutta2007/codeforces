#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,k;
    cin>>n>>k;
    long long int left = n;
    long long int answer=0;
    long long int number=0;
    for(int i=1;i<=k;i++)
    {
      long long int size;
      cin>>size;
      if(left >= n%size)
      {
         left = n%size;
         answer = i;
         number = n/size;
      }
   }
   cout<<answer<<" "<<number<<endl;

    return 0;
}