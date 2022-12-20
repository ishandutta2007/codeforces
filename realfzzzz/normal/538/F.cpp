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
int n,a[maxn];
int ans[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=1;i<=n;i++) a[i]=readint();
    for(int i=2;i<=n;i++){
    	int l=1;
    	while(l<=i-2){
    		int r=(i-2)/((i-2)/l);
    		if(a[(i-2)/l+1]>a[i]){
    			ans[l]++;
    			ans[r+1]--;
			}
			l=r+1;
		}
		if(a[1]>a[i]) ans[l]++;
	}
	for(int i=2;i<n;i++) ans[i]+=ans[i-1];
	for(int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("\n");
    return 0;
}