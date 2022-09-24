#include<cstdio>
#include<algorithm>

using namespace std;
int main(){
  int a, b, c, s;
  scanf("%d%d%d", &a,&b,&c);
  s=0;
  for (int i=0; i<b+c-1; i++) {
    s+=a;
    if (i<min(b,c)-1) a++;
    else if (max(b,c)-2<i) a--;
  }
  printf("%d\n", s);
  return 0;
}