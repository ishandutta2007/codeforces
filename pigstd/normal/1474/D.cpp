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
int t;int n;vector<int>a;vector<int>z,f;
#define chkmn(a,b) (a)=min((a),(b))
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		a=vector<int>(n+1,0);
		f=vector<int>(n+2,0x3f3f3f3f);
		z=vector<int>(n+2,0x3f3f3f3f);
		for(int i=1;i<=n;i++)in::read(a[i]);
		//f[0][i]   f[1][i]
		z[0]=0;for(int i=1;i<=n;i++)if(a[i]>=z[i-1])z[i]=a[i]-z[i-1];
		f[n+1]=0;for(int i=n;i>=1;i--)if(a[i]>=f[i+1])f[i]=a[i]-f[i+1];
		if(z[n]==0)
			puts("YES");
		else{
			bool flag=false;
			for(int i=1;i<=n-1;i++){
				// a[i] a[i+1]
				// z[i-1]  a[i+1] a[i] f[i+2]
				if(a[i+1]>=z[i-1])
					if(a[i]>=a[i+1]-z[i-1])
						if(f[i+2]==a[i]-a[i+1]+z[i-1])
							flag=true;
			}puts(flag?"YES":"NO");
		}
	}
	out::flush();
	return 0;
}