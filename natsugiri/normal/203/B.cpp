#include<cstdio>
int n, m;
int f[1111][1111];

int main(){
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int p=-1; p<2; p++) {
      for (int q=-1; q<2; q++) {
	f[y+p][x+q]++;
	if (f[y+p][x+q]==9) {
	  printf("%d\n", i+1);
	  return 0;
	}
      }
    }
  }
  
  puts("-1");
  return 0;
}