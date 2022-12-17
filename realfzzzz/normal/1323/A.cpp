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
const int maxn=100+5;
int n,a[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	n=readint();
    	for(int i=0;i<n;i++) a[i]=readint();
    	if(n==1&&a[0]%2==1) printf("-1\n");
    	else if(a[0]%2==0) printf("1\n1\n");
    	else if(a[1]%2==0) printf("1\n2\n");
    	else printf("2\n1 2\n");
	}
    return 0;
}