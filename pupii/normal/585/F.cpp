#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,d;
char S[1010],x[60],y[60];
int ch[25010][10],fail[25010],cnt;
bool yes[25010];
int que[25010],hd,tl;
int f[51][25010][2][2];
//f[x][y][o1][o2] x y o1 o2/
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
int work(char*x){
	memset(f,0,sizeof f);
	f[0][0][0][1]=1;
	for(int i=1;i<=d;++i)
		for(int j=0;j<=cnt;++j)
			for(int o1=0;o1<2;++o1)
				for(int o2=0;o2<2;++o2)
					if(f[i-1][j][o1][o2]){
						int lim=o2?x[i]-'0':9;
						for(int k=0;k<=lim;++k)
							add(f[i][ch[j][k]][o1|yes[ch[j][k]]][o2&(k==lim)],f[i-1][j][o1][o2]);
					}
	int ret=0;
	for(int i=0;i<=cnt;++i)add(ret,f[d][i][1][0]),add(ret,f[d][i][1][1]);
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);n=strlen(S+1);
	scanf("%s",x+1);d=strlen(x+1);
	scanf("%s",y+1);
	for(int l=1,r=d>>1;r<=n;++l,++r){
		int x=0;
		for(int i=l;i<=r;++i){
			if(!ch[x][S[i]-'0'])ch[x][S[i]-'0']=++cnt;
			x=ch[x][S[i]-'0'];
		}
		yes[x]=1;
	}
	for(int i=0;i<10;++i)if(ch[0][i])que[tl++]=ch[0][i];
	while(hd^tl){
		int x=que[hd++];
		for(int i=0;i<10;++i)
			if(ch[x][i]){
				fail[ch[x][i]]=ch[fail[x]][i];
				que[tl++]=ch[x][i];
			}else ch[x][i]=ch[fail[x]][i];
	}
	--x[d];for(int i=d;x[i]<'0';--i)x[i]='9',--x[i-1];
	printf("%d\n",(work(y)-work(x)+mod)%mod);
	return 0;
}