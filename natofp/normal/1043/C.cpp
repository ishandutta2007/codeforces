#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a(1001,0);

bool zrob(int k,int n)
{
    for(int i=0;i<k;i++)
    {
        for(int j=i;j<n-k;j+=k) if(a[j]!=a[j+k]) return false;
    }
    return true;
}

int main()
{
  vector<char> s;
  string x; cin>>x;
  for(int i=0;i<x.length();i++) s.push_back(x[i]);
  for(int i=0;i<x.length()-1;i++)
  {
      if((s[i]=='b' && s[i+1]=='a') || (s[i]=='a' && s[i+1]!='a')) {cout<<"1 "; reverse(s.begin(),s.begin()+i+1);}
      else cout<<"0 ";
  }
  if(s[x.length()-1]=='a') cout<<1;
  else cout<<0;


    return 0;
}