#include<bitset>
#include<cstdio>

inline int read(){
	int x=0;char c;
	while((c=getchar())<'0'&&c>'9');
	while(x=x*10+(c^'0'),(c=getchar())>='0'&&c<='9');
	return x;
}

int n,m;
std::bitset<7001>a[100001],mu[7001],sg[7001];

int ip[7001],p[7001],pc,miu[7001];
inline void Init(){
	miu[1]=1;
	for(int i=2;i<=7000;++i){
		if(!ip[i])p[++pc]=i,miu[i]=1;
		for(int j=1,k;j<=pc;++j){
			k=p[j]*i;
			if(k>7000)break;
			ip[k]=1;
			if(i%p[j])miu[k]=miu[i];
			else break;
		}
	}
	for(int i=1;i<=7000;++i){
		for(int j=i;j<=7000;j+=i)sg[j][i]=1,mu[i][j]=miu[j/i];
	}
}

char s[1000002];int t;

int main(){
	Init();
	n=read(),m=read();
	while(m--){
		int opt=read(),x=read(),y,z,v;
		if(opt==1){
			v=read();
			a[x]=sg[v];
		}
		if(opt==2){
			y=read(),z=read();
			a[x]=a[y]^a[z];
		}
		if(opt==3){
			y=read(),z=read();
			a[x]=a[y]&a[z];
		}
		if(opt==4){
			v=read();
			s[t++]=((a[x]&mu[v]).count()&1)^'0';
		}
	}
	printf("%s",s);
	return 0;
}