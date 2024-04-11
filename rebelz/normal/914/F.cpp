#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,opt,x,y;
char s[100005],t[100005];
bitset<100005> b[30],now;

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) b[s[i]-'a'+1][i]=1;
	q=readint();
	char ch;
	while(q--){
		opt=readint(); x=readint();
		if(opt==1){
			scanf("%c",&ch);
			b[s[x]-'a'+1][x]=0,b[ch-'a'+1][x]=1;
			s[x]=ch;
		}
		else{
			y=readint(); scanf("%s",t+1); m=strlen(t+1);
			now=b[t[1]-'a'+1]<<(100005-y-1);
			for(int i=2;i<=m;i++) now&=(b[t[i]-'a'+1]<<(100005-y-1)>>(i-1));
			printf("%d\n",(now>>(100005-y-1+x)).count());
		}
	}
	return 0;
}