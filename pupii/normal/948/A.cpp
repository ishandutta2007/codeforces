// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
using namespace std;
typedef long long ll;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char ch[511][511];
main(){
    int n,m;
    n=gi(),m=gi();
    for(rg int i=1;i<=n;++i)scanf("%s",ch[i]+1);
    for(rg int i=1;i<=n;++i)
    	for(rg int j=1;j<=m;++j){
    		if(ch[i][j]=='S'){
				if(ch[i+1][j]=='W'||ch[i][j+1]=='W'){
    				puts("No");
    				return 0;
    			}
    		}else if(ch[i][j]=='W'){
				if(ch[i+1][j]=='S'||ch[i][j+1]=='S'){
    				puts("No");
    				return 0;
    			}
    		}
		}
	for(rg int i=1;i<=n;++i)
		for(rg int j=1;j<=m;++j)
			if(ch[i][j]=='.')ch[i][j]='D';
	puts("Yes");
    for(rg int i=1;i<=n;++i)printf("%s\n",ch[i]+1);
    return 0;
}