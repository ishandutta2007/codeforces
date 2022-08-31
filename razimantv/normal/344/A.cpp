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

int main()
{
  int cnt=0,last=0;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    int a;
    scanf("%d",&a);
    if(a!=last)cnt++,last=a;
  }
  printf("%d\n",cnt);
  return 0;
}