#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[200005];

int main(){
	n=readint();
	scanf("%s",s+1);
	int flag;
	for(int i=1;i<=n;i++){
		if(s[i]>s[i+1]){
			flag=i;
			break;
		}
	}
	for(int i=1;i<=n;i++) if(i!=flag) printf("%c",s[i]);
	printf("\n");
	return 0;
}