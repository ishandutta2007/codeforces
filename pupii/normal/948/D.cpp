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
int a[300001],p[300001];
int ch[300001*30][2],tot[300001*30],index;
il vd insert(int x){
	int now=0;
	for(rg int i=29;~i;--i){
		if(!ch[now][bool(x&(1<<i))])ch[now][bool(x&(1<<i))]=++index;
		now=ch[now][bool(x&(1<<i))];++tot[now];
	}
}
il int get(int x){
	int ret=0,now=0,o;
	for(rg int i=29;~i;--i){
		o=bool(x&(1<<i));
		if(ch[now][o]&&tot[ch[now][o]])now=ch[now][o];
		else now=ch[now][o^1],ret+=1<<i;
		--tot[now];
	}
	return ret;
}
main(){
	int n=gi();
	for(rg int i=1;i<=n;++i)a[i]=gi();
	for(rg int i=1;i<=n;++i)p[i]=gi(),insert(p[i]);
	for(rg int i=1;i<=n;++i)printf("%d ",get(a[i]));
    return 0;
}