
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
int v[100001];
int t[100001];
priority_queue<int>que;
main(){
	int n=gi();
	for(rg int i=1;i<=n;++i)v[i]=gi();
	for(rg int i=1;i<=n;++i)t[i]=gi();
	int tot=0;
	for(rg int i=1;i<=n;++i){
		que.push(-v[i]-tot);
		tot+=t[i];
		int ans=0;
		while(!que.empty()&&-que.top()<=tot){
			ans+=-que.top()-tot+t[i];
			que.pop();
		}
		printf("%lld ",ans+que.size()*t[i]);
	}
    return 0;
}