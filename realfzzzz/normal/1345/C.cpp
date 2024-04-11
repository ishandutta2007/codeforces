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
const int maxn=2e5;
int n,a[maxn];
int in[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		for(int i=0;i<n;i++) in[i]=0;
		for(int i=0;i<n;i++){
			a[i]=readint();
			if(a[i]>0) a[i]%=n;
			else a[i]=n-(-a[i])%n;
			in[(i+a[i])%n]++;
		}
		bool ok=1;
		for(int i=0;i<n;i++) if(in[i]!=1){
			ok=0;
			break;
		}
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}