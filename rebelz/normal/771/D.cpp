#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[80];
int d[80][80][80][2],a[80],rnk[80],pl[3][80],now[3];

int main(){
	n=readint();
	scanf("%s",s+1);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++){
		if(s[i]!='V'&&s[i]!='K') a[i]=2;
		if(s[i]=='V') a[i]=0;
		if(s[i]=='K') a[i]=1;
	}
	for(int i=1;i<=n;i++) rnk[i]=++now[a[i]],pl[a[i]][now[a[i]]]=i;
	d[0][0][0][0]=0;
	for(int i=0;i<=now[0];i++){
		for(int j=0;j<=now[1];j++){
			for(int k=0;k<=now[2];k++){
				if(i==0&&j==0&&k==0) continue;
				if(i>0){
					int cnt=0;
					for(int l=1;l<=pl[0][i];l++){
						if(a[l]==1&&rnk[l]>j) cnt++;
						if(a[l]==2&&rnk[l]>k) cnt++;
					}
					d[i][j][k][1]=min(d[i][j][k][1],min(d[i-1][j][k][0],d[i-1][j][k][1])+cnt);
				}
				if(j>0){
					int cnt=0;
					for(int l=1;l<=pl[1][j];l++){
						if(a[l]==0&&rnk[l]>i) cnt++;
						if(a[l]==2&&rnk[l]>k) cnt++;
					}
					d[i][j][k][0]=min(d[i][j][k][0],d[i][j-1][k][0]+cnt);
				}
				if(k>0){
					int cnt=0;
					for(int l=1;l<=pl[2][k];l++){
						if(a[l]==0&&rnk[l]>i) cnt++;
						if(a[l]==1&&rnk[l]>j) cnt++;
					}
					d[i][j][k][0]=min(d[i][j][k][0],min(d[i][j][k-1][0],d[i][j][k-1][1])+cnt);
				}
//				cout<<"TEST "<<i<<' '<<j<<' '<<k<<' '<<d[i][j][k][0]<<' '<<d[i][j][k][1]<<endl;
			}
		}
	}
	cout<<min(d[now[0]][now[1]][now[2]][0],d[now[0]][now[1]][now[2]][1])<<endl;
	return 0;
}