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
const int maxn=50+5;
int n,m;
bool a[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		m=readint();
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) a[i][j]=readint();
		int cnt1=0,cnt2=0;
		for(int i=0;i<n;i++){
			bool res=0;
			for(int j=0;j<m;j++) res|=a[i][j];
			cnt1+=res;
		}
		for(int i=0;i<m;i++){
			bool res=0;
			for(int j=0;j<n;j++) res|=a[j][i];
			cnt2+=res;
		}
		if(min(n-cnt1,m-cnt2)%2==0) printf("Vivek\n");
		else printf("Ashish\n");
	}
	return 0;
}