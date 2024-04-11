#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int arr[300011][2] = {{0,0}};

    long long int n;
    cin>>n;
    for(long long int j=0;j<n;j++)
    {
      string s;
      cin>>s;
      long long int max = 0;
      long long int cal=0;
      for(long long int i=0;i<s.length();i++)
      {
         if(s[i]== ')')
            cal++;
         else
            cal--;
         if(cal>max)
            max = cal;
      }
      if(!(max==0 || cal==max))
         continue;
      if(cal<0)
         arr[((long long int)-1)*cal][1]++;
      else
         arr[cal][0]++;
   }
   long long int answer = arr[0][0] * arr[0][0];
   for(long long int i=1;i<300011;i++)
   {
      answer += (arr[i][0] * arr[i][1]);
   }
    cout<<answer<<endl;
    return 0;
}