# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>
# include <cstdlib>

using namespace std;

const long long MOD=1000000007;
int ar[300000];

int main()
{
  int N,K;
  long long seed=1;
  scanf("%d%d",&N,&K);
  seed=(seed*N)%MOD;
  seed=(seed*K)%MOD;

  int minpos=0;
  for(int i=0;i<N;i++)
  {
    scanf("%d",ar+i);
    if(ar[i]<ar[minpos])minpos=i;
    if((N&31)==17)seed=(seed*ar[i])%MOD;
  }
  srand(seed);

  swap(ar[0],ar[minpos]);
  if(ar[0]<=K)
  {
    printf("%d\n",ar[0]);
    return 0;
  }

  for(int ans=ar[0];ans>K+1;ans--)
  {
    if((ar[0]%ans)>K)continue;
    if((ar[N-1]%ans)>K)continue;
    bool flag=true;
    for(int i=1;i<N-1;i++)
    {
      swap(ar[i],ar[i+rand()%(N-1-i)]);
      if((ar[i]%ans)>K)
      {
        flag=false;
        swap(ar[i],ar[N-1]);
        break;
      }
    }
    if(flag)
    {
      printf("%d\n",ans);
      return 0;
    }
  }
  printf("%d\n",K+1);
  return 0;
}