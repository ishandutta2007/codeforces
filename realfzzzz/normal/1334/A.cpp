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
    	int lp=0,lc=0;
    	bool ok=1;
    	for(int i=0;i<n;i++){
    		int p,c;
    		p=readint();
    		c=readint();
    		if(p<lp||c<lc||p-lp<c-lc) ok=0;
    		lp=p;
    		lc=c;
		}
		printf(ok?"YES\n":"NO\n");
	}
    return 0;
}