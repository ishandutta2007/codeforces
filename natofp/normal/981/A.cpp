// C++ program to demonstrate the use of std::nth_element
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool czy(string s,int a,int b)
{
    bool wynik=true;
    for(int i=0;i<(b-a+1)/2;i++)
    {
       if(s[a+i]!=s[b-i]) wynik=false;
    }
    return !wynik;
}

int main()
{

  int x=0;
  string s;
  cin>>s;
  int n=s.length();
  for(int i=0;i<n;i++)
  {
      for(int j=i;j<n;j++)
      {
          if(czy(s,i,j)) {if(j-i+1>x) x=j-i+1;}
      }
  }
  cout<<x;
    return 0;
}