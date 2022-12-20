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
    	int x,n,m;
    	x=readint();
    	n=readint();
    	m=readint();
    	for(int i=0;i<n;i++){
    		if(x/2+10>=x) break;
    		x=x/2+10;
		}
		printf(x<=m*10?"YES\n":"NO\n");
	}
    return 0;
}