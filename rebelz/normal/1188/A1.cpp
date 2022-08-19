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
int du[100005];

int main(){
	n=readint();
	for(int i=1;i<=n-1;i++) du[readint()]++,du[readint()]++;
	for(int i=1;i<=n;i++) if(du[i]==2) return printf("NO\n"),0;
	printf("YES\n");
	return 0;
}