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
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	int n,x,y;
    	n=readint();
    	x=readint();
    	y=readint();
    	printf("%d %d\n",min(max(x+y-n,0)+1,n),min(x+y-1,n));
	}
    return 0;
}