#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110][110];
int n;

int main() {
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		int a,b;
		scanf("%d",&a);
		while(a--) {
			scanf("%d",&b);
			arr[i][b] = 1;
		}
	}
	for(i=0;i<n;i++) {
		int check = 0;
		for(j=0;j<n;j++) {
			if(i == j) continue; 
			for(k=1;k<=100;k++) {
				if(arr[j][k] == 1 && arr[i][k] == 0) {
					break;
				}
			}
			if(k > 100)
				check = 1;
		}
		if(check)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}