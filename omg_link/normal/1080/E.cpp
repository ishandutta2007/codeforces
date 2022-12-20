#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MN 250
typedef long long LL;
const int mod=992333333;
int n,m,xxx=0,b[MN*2+5];
LL ans=0;
int a[MN+5][MN+5][MN+5];
int hsh[26][MN+5];
char s[MN+5][MN+5];
int getrand(){
	int *p=new int;
	static char s[20];
	sprintf(s,"%p",p);
	delete p;
	int x;
	sscanf(s+2,"%x",&x);
	return x;
}
int grand(){return rand()&0x7fff;}
int irand(){return (grand()<<15)|grand();}
int s2[MN*2+5],p[MN*2+5];
int manacher(int len){
	int ans=0;
    for(int i=1;i<=len;i++)
        s2[i<<1]=b[i],s2[i<<1|1]=mod+1;
    s2[0]=mod+2,s2[1]=mod+1;
    len=len<<1|1;
    int id=1,mx=2;
    for(int i=1;i<=len;i++){
        if(i<mx) p[i]=std::min(p[id*2-i],mx-i);
        else p[i]=1;
        while(s2[i-p[i]]==s2[i+p[i]]) p[i]++;
        if(i+p[i]>mx) id=i,mx=i+p[i];
        if(s2[i]>=0) ans+=((p[i])>>1);
    }
    return ans;
}
int main(){
	srand(getrand());
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	for(int i=0;i<26;i++)
		for(int j=1;j<=m;j++)
			hsh[i][j]=irand()%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			static int c[26],cnt,thash;
			cnt=0; thash=0; memset(c,0,sizeof(c));
			for(int k=j;k<=m;k++){
				c[s[i][k]-'a']++;
				if(c[s[i][k]-'a']&1) cnt++;
				else cnt--;
				thash=(thash+hsh[s[i][k]-'a'][c[s[i][k]-'a']])%mod;
				if(cnt>1)
					a[i][j][k]=(--xxx);
				else
					a[i][j][k]=thash;
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int r=l;r<=m;r++){
			for(int i=1;i<=n;i++)
				b[i]=a[i][l][r];
			ans+=manacher(n);
		}
	}
	printf("%lld\n",ans);
}