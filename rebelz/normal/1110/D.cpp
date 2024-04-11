#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,x;
int a[1000005],d[1000005][3][3];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		x=readint();
		a[x]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=2;j++){
			for(int k=0;k<=2;k++){
				for(int l=0;l<=2;l++){
					if(a[i]<j+k+l||a[i+1]<j+k||a[i+2]<j) continue;
					d[i][j][k]=max(d[i][j][k],d[i-1][k][l]+j+(a[i]-j-k-l)/3);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) ans=max(ans,d[m][i][j]);
	cout<<ans<<endl;
	return 0;
}