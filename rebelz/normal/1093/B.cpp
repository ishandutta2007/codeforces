#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char a[105][1005];
int b[105],cnt[105];

int main(){
	int n=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++){
		b[i]=strlen(a[i]+1);
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=b[i];j++) cnt[a[i][j]-'a'+1]++;
		int num=0;
		for(int j=1;j<=26;j++) if(cnt[j]>0) num++;
		if(num==1) printf("-1\n");
		else{
			for(int j=1;j<=26;j++) for(int k=1;k<=cnt[j];k++) printf("%c",j+'a'-1);
			printf("\n");
		}
	}
	return 0;
}