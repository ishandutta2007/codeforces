#include<cstdio>
#include<algorithm>


using namespace std;

int n, m, a[100001], b[100001], c;


int main(){

  scanf("%d%d%d", &n, &m, &c);

  for(int i=0; i<n; i++)scanf("%d", a+i);
  for(int i=0; i<m; i++)scanf("%d", b+i+1);

  for(int i=1; i<m; i++)b[i+1]=(b[i+1]+b[i])%c;

  for(int i=0; i<n; i++)
    printf("%d%c", (c+a[i]+b[min(m, i+1)]-b[max(0, m-n+i)])%c, i+1==n?'\n':' ');
  
  return 0;
}