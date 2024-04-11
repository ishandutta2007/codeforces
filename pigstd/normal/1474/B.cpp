#include<bits/stdc++.h>
//#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=40000+10;
int pr[N],tot;
bool npr[N];
signed main(){
	for(int i=2;i<N;i++){
		if(!npr[i])pr[++tot]=i;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=true;
			if(i%pr[j]==0)continue;
		}
	}
	int t,n;
	in::read(t);
	while(t--){
		in::read(n);
		int fi=*lower_bound(pr+1,pr+1+tot,n+1);
		int se=*lower_bound(pr+1,pr+1+tot,fi+n);
		out::write(1ll*fi*se);
		out::putc('\n');
	}
	out::flush();
	return 0;
}