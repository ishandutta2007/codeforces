#include<vector>
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
int n;
vector<int> g[maxn];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=1;i<n;i++){
    	g[readint()].push_back(i);
    	g[readint()].push_back(i);
	}
	int flag=0;
	for(int i=1;i<=n;i++)
		if(g[i].size()>2) flag=i;
	if(!flag){
		for(int i=0;i<n-1;i++) printf("%d\n",i);
		return 0;
	}
	for(int i=1;i<g[flag][0];i++) printf("%d\n",2+i);
	printf("0\n");
	for(int i=g[flag][0]+1;i<g[flag][1];i++) printf("%d\n",1+i);
	printf("1\n");
	for(int i=g[flag][1]+1;i<g[flag][2];i++) printf("%d\n",i);
	printf("2\n");
	for(int i=g[flag][2]+1;i<n;i++) printf("%d\n",i-1);
    return 0;
}