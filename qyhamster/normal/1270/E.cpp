#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long long x[maxn],y[maxn];
int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  while(true)
  {
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
      if((x[i] + y[i]) % 2) odd++;
      else even++;
    }
    if(odd && even)
    {
      cout << odd << '\n';
      for(int i = 0; i < n; i++)
      {
        if((x[i] + y[i]) % 2) cout << i+1 << " ";
      }
      cout << endl;
      exit(0);
    }
    if(even == 0)
    {
      for(int i = 0; i < n; i++) y[i]++;
    }
    int bodd = 0, beven = 0;
    for(int i = 0; i < n; i++)
    {
      if(x[i]%2) bodd++;
      else beven++;
    }
    if(bodd && beven)
    {
      cout << bodd << '\n';
      for(int i = 0; i < n; i++)
      {
        if(x[i]%2) cout << i+1 << " ";
      }
      cout << endl;
      exit(0);
    }
    if(beven == 0)
    {
      for(int i = 0; i < n; i++)
      {
        x[i]++;
        y[i]++;
      }
    }
    for(int i = 0; i < n; i++)
    {
      x[i] /= 2;
      y[i] /= 2;
    }
  }
  return 0;
}