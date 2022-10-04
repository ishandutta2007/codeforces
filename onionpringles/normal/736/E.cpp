#include <stdio.h>
int cnt[6001];
int d[3000];
void sort(int* a, int* da, int n){
	for(int i=0;i<=6000;i++)cnt[i]=0;
	for(int i=0;i<n;i++)cnt[da[a[i]]]++;
	for(int i=1;i<=6000;i++)cnt[i]+=cnt[i-1];
	for(int i=n-1;i>=0;i--)d[--cnt[da[a[i]]]]=a[i];
	for(int i=0;i<n;i++)a[i]=d[i];
}
int a[3000];
int b[3000];
int bd[3000][3000];
int main(){
	int n,m;scanf("%d%d",&m,&n);
	int sum = 0;
	for(int i=m-1;i>=m-n;i--){
		int x;scanf("%d",&x);
		b[i] = x;
		sum +=x;
		if(sum > m*(m-1)-i*(i-1)){
			puts("no");return 0;
		}
	}
	if(n==m && sum != m*(m-1)){
		puts("no");return 0;
	}
	if(n!=m){
		sum = m*(m-1) - sum;
		int r = sum%(m-n);
		for(int i=0;i<m-n;i++)b[i]=sum/(m-n);
		for(int i=0;i<r;i++)b[m-n-1-i]++;
		if(b[m-n-1]>b[m-n]){
			puts("no");return 0;
		}
	}
	puts("yes");
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			bd[i][j]=1;
		}
	}
	for(int i=0;i<m;i++)a[i]=i;
 	for(int i=m-1;i>=0;i--){
		int ii = a[i];
		int x= b[ii] - m + 1;
		for(int j=0;j<x;j++){
			int jj = a[j];
			b[jj]++;
			b[ii]--;
			bd[ii][jj] = 2;
			bd[jj][ii] = 0;
		}
		sort(a,b,i);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j)printf("%c",'X');
			else if(bd[i][j]==1)printf("%c",'D');
			else if(bd[i][j]==2)printf("%c",'W');
			else printf("%c",'L');
		}
		puts("");
	}
}