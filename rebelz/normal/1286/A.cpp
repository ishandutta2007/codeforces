#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[105],d[105][105][105][2],cnt[2];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) if(a[i]>0) cnt[a[i]&1]++;
	cnt[0]=n/2-cnt[0],cnt[1]=n/2+(n&1)-cnt[1];
	memset(d,0x3f,sizeof(d));
	d[0][0][0][0]=d[0][0][0][1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			for(int l=0;l<=1;l++)
				for(int j=0;j<=cnt[0];j++)
					for(int k=0;k<=cnt[1];k++)
						d[i][j][k][a[i]&1]=min(d[i][j][k][a[i]&1],d[i-1][j][k][l]+(l!=(a[i]&1)));
			continue;
		}
		for(int j=0;j<=cnt[0];j++){
			for(int k=0;k<=cnt[1];k++){
				if(j) d[i][j][k][0]=min(d[i-1][j-1][k][0],d[i-1][j-1][k][1]+1);
				if(k) d[i][j][k][1]=min(d[i-1][j][k-1][0]+1,d[i-1][j][k-1][1]);
			}
		}
	}
	printf("%d\n",min(d[n][cnt[0]][cnt[1]][0],d[n][cnt[0]][cnt[1]][1]));
	return 0;
}