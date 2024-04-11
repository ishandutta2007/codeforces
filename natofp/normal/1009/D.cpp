#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
     while(b)
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main()
{
    vector<pair<int,int> >wynik;
    int n,m;
    cin>>n>>m;
    if(m<n-1) {cout<<"Impossible"; return 0;}
    else
    {
        m-=(n-1);
        for(int i=1;i<n;i++)
            wynik.push_back(make_pair(i,i+1));
    }
    int i=1; int j=3;
    while(m--)
    {
        bool xd=true;
        while(xd)
        {
        if(j>n)
        {
            i++; j=i+2;
            if(i>=(n-1)) {cout<<"Impossible"; return 0;}
        }

        if(gcd(i,j)==1) {wynik.push_back(make_pair(i,j)); xd=false;}
        j++;

        }
    }
    cout<<"Possible"<<endl;
    for(int i=0;i<wynik.size();i++)
        cout<<wynik[i].first<<" "<<wynik[i].second<<endl;

    return 0;
}