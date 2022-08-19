#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a[200005],sum[200005],p[40];

void insert(int x){
	for(int i=30;i>=0;i--){
		if(x&(1<<i)){
			if(!p[i]) return (void)(p[i]=x);
			else x^=p[i];
		}
	}
}

bool check1(int x){
	for(int i=30;i>=0;i--){
		if(x&(1<<i)){
			if(!p[i]) return 1;
			else x^=p[i];
		}
	}
	return 0;
}

bool check2(int x,int y){
	for(int i=30;i>=0;i--){
		if((x^y)&(1<<i)){
			if(p[i]) x^=p[i];
			else return 1;
		}
	}
	return 0;
}

bool dulu(int x,int y) {
	if(!check1(sum[x]^sum[y])) return 1;
	if(x!=n&&!check1(sum[n]^sum[x])) return 1;
	if(!check2(sum[n]^sum[x],sum[x]^sum[y])) return 1;
	return 0;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),sum[i]=sum[i-1]^a[i];
	int pos1=1,pos2=0,ans=0;
	while(pos2<n){
		while(pos1<=n&&dulu(pos1,pos2)) pos1++;
		if(pos1>n) return printf("-1\n"),0;
		ans++;
		insert(sum[pos1]^sum[pos2]);
		pos2=pos1;
	}
	printf("%d\n", ans);
	return 0;
}