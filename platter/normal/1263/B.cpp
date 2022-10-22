#include <cstdio>
using namespace std;

int arr[10][4];
bool check[10];

bool same(int a, int b) {
	for(int i=0;i<4;i++) {
		if (arr[a][i]!=arr[b][i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int c;
	scanf("%d\n", &c);
	for(int t=0;t<c;t++) {
		int n;
		scanf("%d\n", &n);
		for(int i=0;i<10;i++) {
			check[i]=false;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<4;j++) {
				char x;
				scanf("%c",&x);
				int temp=x-'0';
				arr[i][j]=temp;
				if (j==3) {
					check[arr[i][j]]=true;
				}
			}
			scanf("\n");
		}
		bool isfound[10];
		for(int i=0;i<n;i++) {
			isfound[i]=false;
		}
		int type[10];
		for(int ind=0;ind<n;ind++) {
			if (isfound[ind]) {
				continue;
			}
			for(int j=ind;j<n;j++) {
				if ((!isfound[j])&&same(ind,j)) {
					isfound[j]=true;
					type[j]=ind;
				}
			}
		}
		bool isap[10];
		int count=0;
		for(int i=0;i<n;i++) {
			isap[i]=false;
		}
		for(int i=0;i<n;i++) {
			if (!isap[type[i]]) {
				isap[type[i]]=true;
				count+=1;
			}
		}
		printf("%d\n",n-count);
		bool fixed[10];
		for(int i=0;i<n;i++) {
			fixed[i]=false;
		}
		for(int i=0;i<n;i++) {
			fixed[i]=true;
			for(int j=i+1;j<n;j++) {
				if ((!fixed[j])&&(type[i]==type[j])) {
					for(int k=0;k<10;k++) {
						if (!check[k]) {
							arr[j][3]=k;
							fixed[j]=true;
							check[k]=true;
							break;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<4;j++) {
				printf("%d",arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}