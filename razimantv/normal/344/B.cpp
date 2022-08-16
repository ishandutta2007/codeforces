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
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  for(int ab=0;ab<=a;ab++)
  {
    int ac=a-ab;
    int bc1=c-ac;
    int bc2=b-ab;
    if((bc1!=bc2)||(bc1<0))continue;
    printf("%d %d %d\n",ab,bc1,ac);
    return 0;
  }
  printf("Impossible\n");
  return 0;
}