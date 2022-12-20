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
const int maxa=5e5+5;
int n,m;
int f[maxa][20];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    m=readint();
    memset(f,-1,sizeof(f));
    while(n--){
    	int l,r;
    	l=readint();
    	r=readint();
    	f[l][0]=max(f[l][0],r);
	}
	for(int i=1;i<maxa;i++) f[i][0]=max(f[i][0],f[i-1][0]);
	for(int i=1;i<20;i++) for(int j=0;j<maxa;j++)
		if(f[j][i-1]<0) f[j][i]=-1;
		else f[j][i]=f[f[j][i-1]][i-1];
	while(m--){
		int x,y;
		x=readint();
		y=readint();
		int ans=0;
		for(int i=19;i>=0;i--) if(f[x][i]>=0&&f[x][i]<y){
			ans+=1<<i;
			x=f[x][i];
		}
		if(f[x][0]<y) printf("-1\n");
		else printf("%d\n",ans+1);
	}
    return 0;
}