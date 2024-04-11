#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

long long tab[1000007];

long long tsa=-1000000000, tsb=1000000000, tss;

long long f(long long x)
{
     vector <long long> jed, dwa;
     long long ret=0;
     for (int i=1; i<=n; i++)
     {
         if (x<=tab[i])
         {
                      for (int j=i-1; j; j--)
                      {
                          jed.push_back(tab[j]);
                      }
                      for (int j=i; j<=n; j++)
                      {
                          dwa.push_back(tab[j]);
                      }
                      break;
         }
     }
     if (jed.empty() && dwa.empty())
     {
                     for (int i=n; i; i--)
                     {
                         jed.push_back(tab[i]);
                     }
     }
     while(!jed.empty())
     {
                        ret+=(x-jed.back())<<1;
                        for (int i=1; i<=m && !jed.empty(); i++)
                        {
                            jed.pop_back();
                        }
     }
     while(!dwa.empty())
     {
                        ret+=(dwa.back()-x)<<1;
                        for (int i=1; i<=m && !dwa.empty(); i++)
                        {
                            dwa.pop_back();
                        }
     }
     return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    while(tsa<tsb)
    {
                  tss=(tsa+tsb)>>1;
                  if (f(tss)<f(tss+1))
                  {
                                      tsb=tss;
                  }
                  else
                  {
                      tsa=tss+1;
                  }
    }
    printf("%lld", f(tsa));
    return 0;
}