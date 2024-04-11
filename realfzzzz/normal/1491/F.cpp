#include<bits/stdc++.h>
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
const int maxn=2e3+5;
int n;
bool ans[maxn];
int query(int x,int y){
	printf("? %d 1\n",x);
	for(int i=1;i<=x;i++) printf("%d ",i);
	printf("\n%d\n",y);
	fflush(stdout);
	return readint();
}
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) ans[i]=0;
		int x=2;
		for(;x<=n;x++) if(query(x-1,x)) break;
		ans[x]=1;
		for(int i=x+1;i<=n;i++){
			printf("? 1 1\n%d\n%d\n",x,i);
			fflush(stdout);
			if(readint()) ans[i]=1;
		}
		int l=1,r=x-1;
		while(l<r){
			int mid=l+(r-l)/2;
			if(query(mid,x)) r=mid;
			else l=mid+1;
		}
		ans[r]=1;
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=!ans[i];
		printf("! %d ",cnt);
		for(int i=1;i<=n;i++) if(!ans[i]) printf("%d ",i);
		fflush(stdout);
	}
	return 0;
}