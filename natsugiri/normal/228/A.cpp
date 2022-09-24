#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int s[4];

int main(){
  for (int i=0; i<4; i++)  scanf("%d", s+i);
  sort(s, s+4);
  int cnt=0;
  for (int i=1; i<4; i++) if (s[i]==s[i-1]) cnt++;

  printf("%d\n", cnt);
  return 0;
}