#include<cstring>
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
const int maxn=2e5+5;
int n,k,a[maxn];
int s[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		memset(s,0,sizeof(s));
		for(int i=2;i<n;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) s[i]++;
		for(int i=1;i<=n;i++) s[i]+=s[i-1];
		int t=0,l;
		for(int i=1;i<=n+1-k;i++) if(s[i+k-2]-s[i]+1>t){
			t=s[i+k-2]-s[i]+1;
			l=i;
		}
		printf("%d %d\n",t,l);
	}
	return 0;
}