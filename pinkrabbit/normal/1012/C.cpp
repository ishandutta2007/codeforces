#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
int n,a[5005],f[2][2505][3];
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	if(n==1) return 0*puts("0");
	if(n==2) return 0*printf("%d\n",a[1]==a[2]);
	memset(f,0x3f,sizeof f);
	int c=0;
	f[0][0][0]=0;
	f[0][1][1]=max(0,a[1]-a[2]+1);
	f[0][1][2]=max(0,a[2]-a[1]+1);
	F(i,3,n){
		c^=1;
		int hi=i+1>>1;
		F(j,0,hi){
			f[c][j][0]=min(f[c^1][j][0],f[c^1][j][2]);
			if(j) f[c][j][1]=min(f[c^1][j-1][0]+max(0,a[i-1]-a[i]+1),f[c^1][j-1][2]-max(0,a[i-1]-a[i-2]+1)+max(0,a[i-1]-min(a[i-2],a[i])+1));
			if(j) f[c][j][2]=f[c^1][j][1]+max(0,a[i]-a[i-1]+1);
		}
	}
	F(j,1,(n+1)/2) printf("%d ",min(min(f[c][j][0],f[c][j][1]),f[c][j][2]));
	return 0;
}