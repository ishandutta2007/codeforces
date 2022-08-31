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

using namespace std;

int ar[100001],cum[100001];

int main()
{
  int N,l,r,ql,qr;
  scanf("%d%d%d%d%d",&N,&l,&r,&ql,&qr);
  for(int i=1;i<=N;i++)
  {
    scanf("%d",ar+i);
    cum[i]=cum[i-1]+ar[i];
  }

  int best=2000000000;
  for(int i=0;i<=N;i++)
  {
    int cur=l*cum[i]+r*(cum[N]-cum[i]);
    if(i<N-i)cur+=qr*max(N-2*i-1,0);
    else cur+=ql*max(i-(N-i+1),0);
    best=min(best,cur);
  }
  printf("%d\n",best);
  return 0;
}