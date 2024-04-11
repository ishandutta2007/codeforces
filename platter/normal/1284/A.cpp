#include <cstdio>
using namespace std;

int main() {
	int n,m;
	scanf("%d %d\n",&n,&m);
	char first[20][20];
	char second[20][20];
	for(int i=0;i<n;i++) {
		scanf("%s",first[i]);
	}
	scanf("\n");
	for(int i=0;i<m;i++) {
		scanf("%s",second[i]);
	}
	scanf("\n");
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		int x;
		scanf("%d\n",&x);
		int f=(x-1)%n;
		int s=(x-1)%m;
		printf("%s",first[f]);
		printf("%s",second[s]);
		printf("\n");
	}
	return 0;
}