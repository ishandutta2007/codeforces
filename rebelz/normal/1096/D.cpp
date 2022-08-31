#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n;
ll a[100005],d[100005][10];
char s[100005];

int main(){
	n=readint(); scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=readint();
	memset(d,0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='h'){
			for(int j=0;j<=4;j++) if(j!=0&&j!=1) d[i][j]=d[i-1][j];
			d[i][1]=min(d[i][1],min(d[i-1][1],d[i-1][0]));
			d[i][0]=min(d[i][0],d[i-1][0]+a[i]);
		}
		else if(s[i]=='a'){
			for(int j=0;j<=4;j++) if(j!=1&&j!=2) d[i][j]=d[i-1][j];
			d[i][2]=min(d[i][2],min(d[i-1][2],d[i-1][1]));
			d[i][1]=min(d[i][1],d[i-1][1]+a[i]);
		}
		else if(s[i]=='r'){
			for(int j=0;j<=4;j++) if(j!=2&&j!=3) d[i][j]=d[i-1][j];
			d[i][3]=min(d[i][3],min(d[i-1][3],d[i-1][2]));
			d[i][2]=min(d[i][2],d[i-1][2]+a[i]);
		}
		else if(s[i]=='d'){
			for(int j=0;j<=4;j++) if(j!=3&&j!=4) d[i][j]=d[i-1][j];
			d[i][4]=min(d[i][4],min(d[i-1][4],d[i-1][3]));
			d[i][3]=min(d[i][3],d[i-1][3]+a[i]);
		}
		else{
			for(int j=0;j<=4;j++) d[i][j]=d[i-1][j];
		}
//		for(int j=0;j<=4;j++) cout<<d[i][j]<<' ';
//		cout<<endl;
	}
	ll ans=1ll<<60;
	for(int i=0;i<4;i++) ans=min(ans,d[n][i]);
	cout<<ans<<endl;
	return 0;
}