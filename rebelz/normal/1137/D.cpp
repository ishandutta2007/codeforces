#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int k,t;
char s[15];

int main(){
	int cnt=0;
	while(true){
		printf("next %d %d\n",0,1);
		fflush(stdout);
		k=readint();
		for(int i=1;i<=k;i++) scanf("%s",s+1);
		printf("next %d\n",0);
		fflush(stdout);
		k=readint();
		bool fl=true;
		cnt++;
		for(int i=1;i<=k;i++){
			scanf("%s",s+1); t=strlen(s+1);
			if(t==2) fl=false;
		}
		if(!fl) break;
	}
	while(true){
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		k=readint();
		for(int i=1;i<=k;i++) scanf("%s",s+1);
		if(k==1) return printf("done\n"),0;
	}
	return 0;
}