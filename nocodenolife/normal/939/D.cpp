#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string one,two;
    cin>>one>>two;
    int arr[26];
    vector<char> out;
    for(int i=0;i<26;i++)
    {
      arr[i] = i;
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
      if(arr[(int)(one[i] - 'a')] == arr[(int)(two[i] - 'a')])
         continue;
      else
      {
         answer++;
         out.push_back(one[i]);
         out.push_back(two[i]);
         int rep = arr[(int)(one[i] - 'a')];
         int torep = arr[(int)(two[i] - 'a')];
         for(int i=0;i<26;i++)
         {
            if(arr[i] == torep)
               arr[i] = rep;
         }
      }
    }
    cout<<answer<<endl;
    int i= out.size();
    while(i>0)
    {
      char a = out[i-1];
      char b = out[i-2];
      cout<<a<<" "<<b<<endl;
      i-=2;
    }
    return 0;
}