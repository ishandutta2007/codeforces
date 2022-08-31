#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,s,a,b,cnt;
int du[100005];

int main(){
	n=readint(); s=readint();
	for(int i=1;i<=n-1;i++){
		a=readint(); b=readint();
		du[a]++; du[b]++;
	}
	for(int i=1;i<=n;i++) if(du[i]==1) cnt++;
	printf("%.10lf\n",1.0*s/cnt*2);
	return 0;
}