#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
  long long int n;
  int q;
  cin>>n>>q;
  for(;q>0;q--)
  {
      long long int index;
      cin>>index;
      if(index%2==0)
      {
        long long int jump =n-(index/2);
        while(jump%2==0)
        {
            index+=jump;
            jump/=2;
        }
        index+=jump;
      }
      cout<<(index+1)/2<<endl;
  }
  
  return 0;
}