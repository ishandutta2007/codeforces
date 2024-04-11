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
int n,x,a[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	n=readint();
    	x=readint();
    	for(int i=0;i<n;i++) a[i]=readint();
    	sort(a,a+n);
    	long long sum=0;
    	bool flag=1;
    	for(int i=n-1;i>=0;i--){
    		sum+=a[i];
    		if(sum<1ll*(n-i)*x){
    			printf("%d\n",n-i-1);
    			flag=0;
    			break;
			}
		}
		if(flag) printf("%d\n",n);
	}
    return 0;
}