#include <stdio.h>
#define INF 999999999

char a[200],b[200];
int p[10],q[10];

int main() {
	int i,j;
	for(i=0;i<10;i++)
		p[i] = q[i] = 0;
	scanf("%s %s",a,b);
	for(i=0;a[i];i++) {
		if(a[i] == '2') p[5]++;
		else if(a[i] == '6') p[9]++;
		else p[a[i]-'0']++;
	}
	for(i=0;b[i];i++) {
		if(b[i] == '2') q[5]++;
		else if(b[i] == '6') q[9]++;
		else q[b[i]-'0']++;
	}
	j = INF;
	for(i=0;i<10;i++) {
		if(p[i]) {
			if(q[i]/p[i] < j)
				j = q[i]/p[i];
		}
	}
	printf("%d\n",j);
	return 0;
}