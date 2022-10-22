#include <bits/stdc++.h>
using namespace std;

int arr[2000][2000];
bool col[2000][2000];
bool cor[2000][2000];
bool rou[2000][2000];
bool rod[2000][2000];
bool cc[2000];
bool cr[2000];
int cnt[2000][2000];
int rnt[2000][2000];
int csum[2000][2000];
int rsum[2000][2000];

int main(void) {
	int n,k;
	scanf("%d %d\n",&n,&k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			char x;
			scanf("%c",&x);
			if (x=='B') {
				arr[i][j]=1;
			}
		}
		scanf("\n");
	}
	for(int i=0;i<n;i++) {
		bool flag=true;
		for(int j=0;j<n;j++) {
			if (arr[i][j]==1) {
				flag=false;
			}
			col[i][j]=flag;
		}
		if (flag) {
			cc[i]=true;
		}
		flag=true;
		for(int j=n-1;j>=0;j--) {
			if (arr[i][j]==1) {
				flag=false;
			}
			cor[i][j]=flag;
		}
	}
	for(int j=0;j<n;j++) {
		bool flag=true;
		for(int i=0;i<n;i++) {
			if (arr[i][j]==1) {
				flag=false;
			}
			rou[i][j]=flag;
		}
		if (flag) {
			cr[j]=true;
		}
		flag=true;
		for(int i=n-1;i>=0;i--) {
			if (arr[i][j]==1) {
				flag=false;
			}
			rod[i][j]=flag;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<=n-k;j++) {
			if ((j==0||col[i][j-1])&&(j==n-k||cor[i][j+k])) {
				if (!cc[i]) {
					cnt[i][j]=1;
				}
			}
		}
	}
    for(int i=0;i<=n-k;i++) {
        for(int j=0;j<n;j++) {
			if ((i==0||rou[i-1][j])&&(i==n-k||rod[i+k][j])) {
				if (!cr[j]) {
					rnt[i][j]=1;
				}
			}
        }
    }
	for(int j=0;j<=n-k;j++) {
		int sum=0;
		for(int i=0;i<k;i++) {
			sum+=cnt[i][j];
		}
		csum[0][j]=sum;
		for(int i=1;i<=n-k;i++) {
			csum[i][j]=csum[i-1][j]-cnt[i-1][j]+cnt[i+k-1][j];
		}
	}
	for(int i=0;i<=n-k;i++) {
		int sum=0;
		for(int j=0;j<k;j++) {
			sum+=rnt[i][j];
		}
		rsum[i][0]=sum;
		for(int j=1;j<=n-k;j++) {
			rsum[i][j]=rsum[i][j-1]-rnt[i][j-1]+rnt[i][j+k-1];
		}
	}
	int ret=0;
	for(int i=0;i<=n-k;i++) {
		for(int j=0;j<=n-k;j++) {
		    //printf("%d %d\n",csum[i][j],rsum[i][j]);
			ret=max(ret,csum[i][j]+rsum[i][j]);
		}
	}
	for(int i=0;i<n;i++) {
		if (cc[i]) {
			ret++;
		}
		if (cr[i]) {
			ret++;
		}
	}
	printf("%d",ret);
}