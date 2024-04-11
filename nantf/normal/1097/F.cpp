#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,q,mu[7007],pr[7007],pl;
bitset<7007> s[maxn],e[maxn],m[maxn];
bool vis[7007];
void init(){
	mu[1]=1;
	FOR(i,2,7000){
		if(!vis[i]) mu[pr[++pl]=i]=-1;
		for(int j=1;j<=pl && i*pr[j]<=7000;j++){
			vis[i*pr[j]]=true;
			if(i%pr[j]) mu[i*pr[j]]=-mu[i];
			else break;
		}
	}
	FOR(i,1,7000) FOR(j,1,7000/i){
		e[i*j][i]=1;
		m[i][i*j]=mu[j];
	}
}
int main(){
	init();
	n=read();q=read();
	FOR(i,1,q){
		int op=read(),x=read(),y=read();
		switch(op){
			case 1:
				s[x]=e[y];break;
			case 2:
				s[x]=s[y]^s[read()];break;
			case 3:
				s[x]=s[y]&s[read()];break;
			case 4:
				printf("%d",(s[x]&m[y]).count()&1);
		}
	}
}