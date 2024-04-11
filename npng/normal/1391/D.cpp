#include <cstdio>
#include <cstring>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=1000000;
char s[5][Maxn+5];
char mp[5];
int f[Maxn+5][8];
bool able[8][8];
int n,m;
int count(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n>=4&&m>=4){
		puts("-1");
		return 0;
	}
	if(n==1||m==1){
		puts("0");
		return 0;
	}
	if(n>m){
		for(int i=1;i<=n;i++){
			scanf("%s",mp+1);
			for(int j=1;j<=m;j++){
				s[j][i]=mp[j];
			}
		}
		n^=m^=n^=m;
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
	}
	memset(f,0x3f,sizeof f);
	if(n==2){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if((count(i)+(count(j)))&1){
					able[i][j]=1;
				}
			}
		}
		f[0][0]=f[0][1]=f[0][2]=f[0][3]=0;
		for(int i=1;i<=m;i++){
			for(int j=0;j<4;j++){
				int val=((s[1][i]-'0')<<1|(s[2][i]-'0'));
				val=count(val^j);
				for(int k=0;k<4;k++){
					if(able[k][j]){
						f[i][j]=min(f[i][j],f[i-1][k]+val);
					}
				}
			}
		}
		int ans=f[m][0];
		for(int i=0;i<4;i++){
			ans=min(ans,f[m][i]);
		}
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(((count(i>>1)+count(j>>1))&1)&&((count(i&3)+count(j&3))&1)){
				able[i][j]=1;
			}
		}
	}
	for(int i=0;i<8;i++){
		f[0][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<8;j++){
			int val=(((s[1][i]-'0')<<2)|((s[2][i]-'0')<<1)|(s[3][i]-'0'));
			val=count(val^j);
			for(int k=0;k<8;k++){
				if(able[k][j]){
					f[i][j]=min(f[i][j],f[i-1][k]+val);
				}
			}
		}
	}
	int ans=f[m][0];
	for(int i=0;i<8;i++){
		ans=min(ans,f[m][i]);
	}
	printf("%d\n",ans);
	return 0;
}