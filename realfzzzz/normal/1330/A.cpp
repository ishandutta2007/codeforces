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
bool a[300];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	int n,x;
    	n=readint();
    	x=readint();
    	memset(a,0,sizeof(a));
    	while(n--) a[readint()]=1;
    	for(int i=1;i<300;i++){
    		if(!a[i]) x--;
    		if(x==-1){
    			printf("%d\n",i-1);
    			break;
			}
		}
	}
    return 0;
}