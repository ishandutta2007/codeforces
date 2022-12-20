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
const int maxn=1e5+5;
int n,m,l[maxn];
long long s[maxn],ans[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    for(int i=1;i<=m;i++) l[i]=readint();
    for(int i=m;i>0;i--) s[i]=s[i+1]+l[i];
    if(s[1]<n){
    	printf("-1\n");
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(ans[i-1]+l[i]>n){
			printf("-1\n");
			return 0;
		}
		ans[i]=max(ans[i-1]+1,n-s[i]+1);
	}
	for(int i=1;i<=m;i++) printf("%d ",(int)ans[i]);
	printf("\n");
    return 0;
}