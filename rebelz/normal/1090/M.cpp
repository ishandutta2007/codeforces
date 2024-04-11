#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int num[200000];

int main(){
  scanf("%d %d",&n,&k);
  for(int i = 1;i<=n;i++){
    scanf("%d",&num[i]);
  }
  int l = 1,ans = 0;
  for(int i = 1;i<=n;i++){
    if(num[i] == num[i-1]){
      l = i;
    }
    ans = max(ans,i-l+1);
  }
  printf("%d\n",ans);
  return 0;
}