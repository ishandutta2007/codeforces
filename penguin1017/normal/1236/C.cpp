#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
using namespace std;
int a[305][305];
int main()
{
	int n;
	scanf("%d",&n);
	int num=1;
	rep(j,0,n){
		if(j&1)rep(i,0,n)a[i][j]=num++;
		else per(i,0,n)a[i][j]=num++;
	}
	rep(i,0,n){
		rep(j,0,n)printf("%d ",a[i][j]);
		printf("\n");
	}
}