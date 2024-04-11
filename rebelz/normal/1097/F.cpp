#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,tot,cnt;
bitset<7005> b[100005],bas[7005];
bool flag[7005];
int prime[7005],g[7005],mu[7005];

void getprime(){
	memset(flag,true,sizeof(flag)); flag[1]=false;
	g[++cnt]=1,mu[1]=1;
	for(int i=2;i<=7000;i++){
		if(flag[i]) prime[++tot]=i,mu[i]=1;
		for(int j=1;j<=tot&&i*prime[j]<=7000;j++){
			flag[i*prime[j]]=false;
			mu[i*prime[j]]=mu[i];
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
		}
		if(mu[i]==1) g[++cnt]=i;
	}
}

int main(){
	getprime();
	n=readint(); q=readint();
	for(int i=1;i<=7000;i++) for(int j=1;j<=cnt&&i*g[j]<=7000;j++) bas[i][i*g[j]]=1;
	int opt,x,y,z;
	for(int i=1;i<=q;i++){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			b[x].reset();
			for(int j=1;j<=sqrt(y);j++)	if(y%j==0) b[x][j]=b[x][y/j]=1;
		}
		else if(opt==2){
			z=readint();
			b[x]=b[y]^b[z];
		}
		else if(opt==3){
			z=readint();
			b[x]=b[y]&b[z];
		}
		else printf("%d",(b[x]&bas[y]).count()%2);
	}
	printf("\n");
	return 0;
}