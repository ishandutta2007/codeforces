#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int cys=998244353;

int n;
ll a[100005],d[100005][205][3],cnt[205][3];

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	memset(d,0,sizeof(d));
	if(a[1]>-1)
		d[1][a[1]][1]=1;
	else
		for(int i=1;i<=200;i++)
			d[1][i][1]=1;
	for(int j=1;j<=200;j++)
		cnt[j][0]=(cnt[j-1][0]+d[1][j][0])%cys,cnt[j][1]=(cnt[j-1][1]+d[1][j][1])%cys,cnt[j][2]=(cnt[j-1][2]+d[1][j][2])%cys;
	for(int i=2;i<=n;i++){
		if(a[i]>-1){
			d[i][a[i]][0]=(cnt[200][0]-cnt[a[i]][0]+cnt[200][2]-cnt[a[i]][2])%cys;
			d[i][a[i]][1]=(cnt[a[i]-1][0]+cnt[a[i]-1][1]+cnt[a[i]-1][2])%cys;
			d[i][a[i]][2]=(cnt[a[i]][0]-cnt[a[i]-1][0]+cnt[a[i]][1]-cnt[a[i]-1][1]+cnt[a[i]][2]-cnt[a[i]-1][2])%cys;
		}
		else{
			for(int j=1;j<=200;j++){
				d[i][j][0]=(cnt[200][0]-cnt[j][0]+cnt[200][2]-cnt[j][2])%cys;
				d[i][j][1]=(cnt[j-1][0]+cnt[j-1][1]+cnt[j-1][2])%cys;
				d[i][j][2]=(cnt[j][0]-cnt[j-1][0]+cnt[j][1]-cnt[j-1][1]+cnt[j][2]-cnt[j-1][2])%cys;
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=200;j++)
			cnt[j][0]=(cnt[j-1][0]+d[i][j][0])%cys,cnt[j][1]=(cnt[j-1][1]+d[i][j][1])%cys,cnt[j][2]=(cnt[j-1][2]+d[i][j][2])%cys;
	}
	ll ans=0;
	for(int i=1;i<=200;i++)
		ans=(ans+d[n][i][0]+d[n][i][2])%cys;
	printf("%d\n",(ans+cys)%cys);
	return 0;
}