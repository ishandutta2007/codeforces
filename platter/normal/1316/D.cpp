#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000][1000];
int ret[1000][1000];

bool valid(int x,int y) {
	return x>=0&&x<n&&y>=0&&y<n;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char s[4]={'D','R','U','L'};

int p[1000005];

int find(int a) {
	if (p[a]<0) {
		return a;
	}
	p[a]=find(p[a]);
	return p[a];
}

void merge(int a,int b) {
	a=find(a);
	b=find(b);
	if (a==b)
	return;
	p[a]+=p[b];
	p[b]=a;
}

void getret(int x,int y,int dir) {
	if (arr[x][y]==x*n+y) {
		ret[x][y]=-1;
	}
	else {
		ret[x][y]=dir;
	}
	for(int k=0;k<4;k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if (valid(nx,ny)) {
			if (arr[x][y]==arr[nx][ny]) {
				if (ret[nx][ny]==-3) {
					int nd=(k+2)%4;
					getret(nx,ny,nd);
				}
			}
		}
	}
}

int main(void) {
	memset(p,-1,sizeof(p));
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int x,y;
			scanf("%d %d ",&x,&y);
			if (x==-1&&y==-1) {
				arr[i][j]=-1;
			}
			else {
				x--;
				y--;
				arr[i][j]=n*x+y;
			}
		}
		scanf("\n");
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (arr[i][j]!=-1) {
				int val=arr[i][j];
				int x=val/n;
				int y=val%n;
				if (arr[x][y]!=val) {
					printf("INVALID");
					return 0;
				}
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<4;k++) {
				if (valid(i+dx[k],j+dy[k])) {
					int x=i+dx[k];
					int y=j+dy[k];
					if (arr[x][y]==arr[i][j]) {
						merge(i*n+j,x*n+y);
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (arr[i][j]==-1) {
				if (p[find(i*n+j)]==-1) {
					printf("INVALID");
					return 0;
				}
			}
			else {
				if (find(arr[i][j])!=find(i*n+j)) {
					printf("INVALID");
					return 0;
				}
			}
		}
	}
	printf("VALID\n");
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			ret[i][j]=-3;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (arr[i][j]==-1) {
				for(int k=0;k<4;k++) {
					int x=i+dx[k];
					int y=j+dy[k];
					if (valid(x,y)) {
						if (arr[x][y]==arr[i][j]) {
							ret[i][j]=k;
							break;
						}
					}
				}
			}
			else if (arr[i][j]==i*n+j) {
				getret(i,j,-1);
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (ret[i][j]==-1) {
				printf("X");
			}
			else {
				printf("%c",s[ret[i][j]]);
			}
		}
		printf("\n");
	}
}