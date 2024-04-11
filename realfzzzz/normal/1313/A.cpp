#include<algorithm>
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
int d[15][15][15][1<<10];
int dp(int a,int b,int c,int s){
	int& ans=d[a][b][c][s];
	if(ans>=0) return ans;
	ans=0;
	if(!((s>>0)&1)&&a>0) ans=max(ans,dp(a-1,b,c,s|(1<<0))+1);
	if(!((s>>1)&1)&&b>0) ans=max(ans,dp(a,b-1,c,s|(1<<1))+1);
	if(!((s>>2)&1)&&c>0) ans=max(ans,dp(a,b,c-1,s|(1<<2))+1);
	if(!((s>>3)&1)&&a>0&&b>0) ans=max(ans,dp(a-1,b-1,c,s|(1<<3))+1);
	if(!((s>>4)&1)&&b>0&&c>0) ans=max(ans,dp(a,b-1,c-1,s|(1<<4))+1);
	if(!((s>>5)&1)&&c>0&&a>0) ans=max(ans,dp(a-1,b,c-1,s|(1<<5))+1);
	if(!((s>>6)&1)&&a>0&&b>0&&c>0) ans=max(ans,dp(a-1,b-1,c-1,s|(1<<6))+1);
	return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t=readint();
    memset(d,-1,sizeof(d));
    while(t--){
    	int a,b,c;
    	a=readint();
    	b=readint();
    	c=readint();
    	printf("%d\n",dp(a,b,c,0));
	}
    return 0;
}