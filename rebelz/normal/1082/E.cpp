#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,c;
int a[500005],s1[500005],s2[500005],lst[500005],now[500005],d[500005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main(){
	n=readint(); c=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) s1[i]=s1[i-1]+(a[i]==c);
	for(int i=n;i>=1;i--) s2[i]=s2[i+1]+(a[i]==c);
	for(int i=1;i<=n;i++){
		lst[i]=now[a[i]];
		now[a[i]]=i;
	}
	for(int i=1;i<=n;i++) d[i]=max(s1[i-1]+1,d[lst[i]]+1);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]+s2[i+1]);
	printf("%d\n",ans);
	return 0;
}