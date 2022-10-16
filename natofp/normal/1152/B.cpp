#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(int x)
{
    while(x>0)
    {
        if(x%2==0) return false;
        x/=2;
    }
    return true;
}

 vector<int> ruchy;
 int ile=0;
 int x;

 void zrob()
 {
     int t=x;
     int res=0;
     while(t>0)
     {
         res++;
         t/=2;
     }
     for(int i=res-1;i>=0;i--)
     {
         if((x&(1<<i))==0)
         {
             ruchy.push_back(i+1);
             x^=((1<<i+1)-1);
             return;
         }
     }
 }

int main()
{
    cin>>x;
    while(czy(x)==false)
    {
        ile++;
        if(ile%2==0)
        {
            x++;
            continue;
        }
        else
        {
            zrob();
        }
    }
    cout<<ile<<endl;
    for(int i=0;i<ruchy.size();i++) cout<<ruchy[i]<<" ";
    return 0;
}