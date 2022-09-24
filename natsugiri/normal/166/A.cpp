#include<cstdio>
#include<algorithm>

using namespace std;

struct DATA_T{int p,t;};
bool cmp(DATA_T a,DATA_T b){
  if(a.p!=b.p)return a.p>b.p;
  return a.t<b.t;
}

DATA_T a[99];

int n,k;

int main(){
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    int p,t;
    scanf("%d%d",&p,&t);
    a[i]=(DATA_T){p,t};
  }
  sort(a,a+n,cmp);
  int ans=0;
  for(int i=0;i<n;i++)
    if(a[k-1].p==a[i].p && a[k-1].t==a[i].t)ans++;
  
  printf("%d\n",ans);
  return 0;
}