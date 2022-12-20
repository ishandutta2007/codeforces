#include<cctype>
#include<cstdio>
using namespace std;
typedef long long ll;
inline ll readint(){
    ll x=0;
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
void solve(int u,int n,ll l,ll r){
	if(n==1) return;
	if(r<=2*(n-1)) for(int i=l;i<=r;i++){
		if(i%2==1) printf("%d ",u);
		else printf("%d ",u+i/2);
	}
	else if(l>2*(n-1)) solve(u+1,n-1,l-2*(n-1),r-2*(n-1));
	else{
		for(int i=l;i<=2*(n-1);i++)
			if(i%2==1) printf("%d ",u);
			else printf("%d ",u+i/2);
		solve(u+1,n-1,1,r-2*(n-1));
	}
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    while(t--){
    	int n=readint();
    	ll l,r;
    	l=readint();
    	r=readint();
    	if(r==1ll*n*(n-1)+1){
    		if(l==r) printf("1\n");
			else{
				solve(1,n,l,r-1);
				printf("1\n");
			}
		}
		else{
			solve(1,n,l,r);
			printf("\n");
		}
	}
    return 0;
}