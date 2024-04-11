#include<algorithm>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=500+5;
int n,a[maxn];
bool b[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		for(int i=0;i<n;i++) a[i]=readint();
		bool c[2];
		c[0]=c[1]=0;
		for(int i=0;i<n;i++) c[b[i]=readint()]=1;
		bool ok=0;
		if(c[0]&&c[1]) ok=1;
		bool ok2=1;
		for(int i=1;i<n;i++) if(a[i]<a[i-1]){
			ok2=0;
			break;
		}
		ok|=ok2;
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}