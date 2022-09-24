#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, h[5555];
int cnt[5555], high[5555];
int main(){
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", h+i);
  high[0]=h[0];
  for (int i=1; i<n; i++) high[i]=high[i-1]+h[i], cnt[i]=i;
  
  cnt[0]=0; high[0]=h[0];
  for (int i=1; i<n; i++) {
	int t=0;
	for (int j=i; j>0; j--) {
	  t+=h[j];
	  if (high[j-1]<=t) {
		cnt[i]=cnt[j-1]+i-j;
		high[i]=t;
		break;
	  }
	}
  }
  printf("%d\n", cnt[n-1]);
  return 0;
}