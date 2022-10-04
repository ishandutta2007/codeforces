#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int A,B,X;
int D[500];
int main(){
	scanf("%d%d%d",&A,&B,&X); ++X;
	int a=0,b=0;
	for(int i=1;i<=X;++i) D[i]=1, ++(i&1?a:b);
	if(a>A||b>B){
		swap(A,B);
		D[1]+=A-a;
		D[2]+=B-b;
		for(int i=1;i<=X;++i){
			for(int j=1;j<=D[i];++j)
				printf("%d",i&1?1:0);
		}
		return 0;
	}
	D[1]+=A-a;
	D[2]+=B-b;
	for(int i=1;i<=X;++i){
		for(int j=1;j<=D[i];++j)
			printf("%d",i&1?0:1);
	}
	return 0;
}