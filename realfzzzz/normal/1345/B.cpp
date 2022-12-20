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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		int n=readint();
		int cnt=0;
		while(n>=2){
			int l=1,r=n;
			while(l<r){
				int mid=l+(r-l+1)/2;
				if(1ll*mid*(3*mid+1)/2<=n) l=mid;
				else r=mid-1;
			}
			n-=r*(3*r+1)/2;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}