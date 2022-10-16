#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int,int> a;
int tab[31];

int policz(int n)
{
    int odp=0;
    int i=30;
    while(i>=0)
    {
        if(n>=tab[i])
        {

            int l=n/tab[i];
            int d=min(l,a[tab[i]]);
            odp+=d;
            n-=d*tab[i];

        }
        i--;
    }
    if(n>0) return -1;
    else return odp;

}

int main()
{
   int n,q;
   cin>>n>>q;

  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      a[x]++;
  }
  for(int i=0;i<31;i++)
    tab[i]=pow(2,i);
  for(int i=0;i<q;i++)
  {
      int x;
      cin>>x;
      cout<<policz(x)<<endl;
  }



    return 0;
}