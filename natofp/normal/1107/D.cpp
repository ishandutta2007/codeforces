#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool tab[5555][5555];
string zamien(char x)
{
    if(x=='0') return "0000";
    if(x=='1') return "0001";
    if(x=='2') return "0010";
    if(x=='3') return "0011";
    if(x=='4') return "0100";
    if(x=='5') return "0101";
    if(x=='6') return "0110";
    if(x=='7') return "0111";
    if(x=='8') return "1000";
    if(x=='9') return "1001";
    if(x=='A') return "1010";
    if(x=='B') return "1011";
    if(x=='C') return "1100";
    if(x=='D') return "1101";
    if(x=='E') return "1110";
    if(x=='F') return "1111";
}
int n;
bool czykwadrat(int x,int y,int ile)
{
    for(int i=x;i<x+ile;i++)
    {
        for(int j=y;j<y+ile;j++)
        {
            if(tab[i][j]!=tab[x][y]) return false;
        }
    }
    return true;
}

bool czy(int x)
{
    for(int i=1;i<=n;i+=x)
    {
        for(int j=1;j<=n;j+=x)
        {
            if(czykwadrat(i,j,x)==false) return false;
        }
    }
    return true;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
  for(int i=1;i<=n;i++)
  {
      string w; cin>>w;
      for(int j=1;j<=n/4;j++)
      {
          char x; x=w[j-1];
          string t=zamien(x);
          tab[i][(j-1)*4+1]=t[0]-'0';
          tab[i][(j-1)*4+2]=t[1]-'0';
          tab[i][(j-1)*4+3]=t[2]-'0';
          tab[i][(j-1)*4+4]=t[3]-'0';
      }
  }
  /*for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          cout<<tab[i][j];
      }
      cout<<endl;
  }*/
  vector<int> dzielniki;
  for(int i=1;i<=n;i++)
  {
      if(n%i==0) dzielniki.push_back(i);
  }
  int hi=dzielniki.size()-1;
  int lo=0;
  while(lo+1<hi)
  {
        int mid=(lo+hi);
        if(czy(dzielniki[mid])==true) lo=mid;
        else hi=mid-1;
  }
  while(czy(dzielniki[hi])==false) hi--;
  cout<<dzielniki[hi];

    return 0;
}