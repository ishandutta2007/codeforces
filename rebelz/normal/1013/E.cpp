#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n;
int a[5005],d[5005][2505][5];

int f(int x){
	if(x<=0)
		return 0;
	return x;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=a[n+1]=-1<<30;
	memset(d,0x3f,sizeof(d));
	d[1][0][0]=0,d[1][1][2]=f(a[2]-a[1]+1);
	for(int i=2;i<=n;i++){
		for(int j=0;j<=(i+1)/2;j++){
			d[i][j][0]=min(d[i-1][j][0],d[i-1][j][1]);
			d[i][j][1]=d[i-1][j][2];
			if(j!=0)
				d[i][j][2]=min(d[i-1][j-1][1]+f(min(a[i-2]-1,a[i-1])-(a[i]-1))+f(a[i+1]-a[i]+1),d[i-1][j-1][0]+f(a[i-1]-a[i]+1)+f(a[i+1]-a[i]+1));
		}
	}
	for(int i=1;i<=(n+1)/2;i++)
		cout<<min(min(d[n][i][0],d[n][i][1]),d[n][i][2])<<' ';
	cout<<endl;
	return 0;
}