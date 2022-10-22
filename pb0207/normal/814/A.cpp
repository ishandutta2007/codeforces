#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=10000;
int a[maxn];
int main(){
  int n,m;scanf("%d%d",&n,&m);
  if(m==1){
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    int x;
    scanf("%d",&x);
    for(int i=1;i<=n;++i){
      if(a[i]==0)a[i]=x;
    }
    for(int i=1;i<n;++i){
      if(a[i]>a[i+1]){
        printf("Yes\n");
        return 0;
      }
    }
    printf("No\n");
  }else printf("Yes\n");
  return 0;
}