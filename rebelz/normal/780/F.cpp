#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
bitset<505> d[505][61][2];
bool vis[505],nv[505];

int main(){
	n=readint(); m=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		d[x][0][z][y]=1;
	}
	for(int i=1;i<=60;i++){
		for(int j=1;j<=n;j++){
			for(int t=0;t<=1;t++){
				for(int k=1;k<=n;k++)
					if(d[j][i-1][t][k]==1)
						d[j][i][t]|=d[k][i-1][t^1];
			}
		}
	}
	if(d[1][60][0].any()) return printf("-1\n"),0;
	int tt=0; ll ans=0;
	vis[1]=true;
	for(int i=59;i>=0;i--){
		memset(nv,false,sizeof(nv));
		bool fl=false;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			for(int k=1;k<=n;k++) if(d[j][i][tt][k]==1) nv[k]=true,fl=true;
		}
		if(fl) memcpy(vis,nv,sizeof(vis)),ans+=1ll<<i,tt^=1;
	}
	cout<<(ans>1e18?-1:ans)<<endl;
	return 0;
}