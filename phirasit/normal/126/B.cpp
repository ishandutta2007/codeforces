#include <stdio.h>
#include <string.h>

#define N 1000010

int p[N];
char s[N];
bool a[N];

int main() {
  scanf("%s", s+1);
  int l = strlen(s+1);
  for(int i = 2;i<=l;i++) {
  	int k;
    for(k = p[i-1]; k > 0 && s[k+1]!=s[i]; k=p[k]);
		p[i]= k + (s[k+1]==s[i]);
  }
  for(int i = 2;i < l; i++) {
		a[p[i]]=true;
	}
  int k;
  for(k = p[l]; k>0; k = p[k]) {
		if(a[k]) {
			break;
		}
	}
  if(k==0) {
		puts("Just a legend");
	}else {
		for(int i=1; i<=k; i++) {
			putchar(s[i]);
		}
	}
  return 0;
}