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
int n;
char s[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	n=readint();
    	scanf("%s",s);
    	int cur=n,res=0;
    	for(int i=0;i<n-1;i++)
    		if(s[i]=='>'){
			    for(int i=cur-res;i<=cur;i++) printf("%d ",i);
			    cur-=res+1;
    			res=0;
			}
			else res++;
		for(int i=cur-res;i<=cur;i++) printf("%d ",i);
		printf("\n");
    	cur=1,res=0;
    	for(int i=0;i<n-1;i++)
    		if(s[i]=='<'){
			    for(int i=cur+res;i>=cur;i--) printf("%d ",i);
			    cur+=res+1;
    			res=0;
			}
			else res++;
		for(int i=cur+res;i>=cur;i--) printf("%d ",i);
		printf("\n");
	}
    return 0;
}