#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q;
int lg2[1005],a[1005][1005];
short st[11][11][1005][1005];

bool check(int x1,int y1,int x2,int y2,int k){
	int gx=lg2[x2-x1-k+1],gy=lg2[y2-y1-k+1];
//	cout<<"TEST "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<k<<' '<<gx<<' '<<gy<<endl;
	return max(max(st[gx][gy][x1][y1],st[gx][gy][x2-k-(1<<gx)+2][y2-k-(1<<gy)+2]),max(st[gx][gy][x1][y2-k-(1<<gy)+2],st[gx][gy][x2-k-(1<<gx)+2][y1]))>=k;
}

int main(){
	n=readint(); m=readint();
	for(int i=2;i<=max(n,m);i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
	for(int i=n;i>=1;i--) 
		for(int j=m;j>=1;j--)
			st[0][0][i][j]=a[i][j]?min(st[0][0][i+1][j],st[0][0][i][j+1])+a[i+min(st[0][0][i+1][j],st[0][0][i][j+1])][j+min(st[0][0][i+1][j],st[0][0][i][j+1])]:0;
	for(int i=0;i<=10;i++)
		for(int j=0;j<=10;j++)
			for(int k=1;k+(1<<i)-1<=n;k++)
				for(int l=1;l+(1<<j)-1<=m;l++){
					if(i>0) st[i][j][k][l]=max(st[i][j][k][l],max(st[i-1][j][k][l],st[i-1][j][k+(1<<i-1)][l]));
					if(j>0) st[i][j][k][l]=max(st[i][j][k][l],max(st[i][j-1][k][l],st[i][j-1][k][l+(1<<j-1)]));
				}
	q=readint();
	int x1,y1,x2,y2;
	while(q--){
		x1=readint(); y1=readint(); x2=readint(); y2=readint();
		int l=1,r=min(y2-y1+1,x2-x1+1),ans=0,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(x1,y1,x2,y2,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}