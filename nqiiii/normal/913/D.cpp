#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200000;
int n,t,a[maxn+10],tm[maxn+10],id[maxn+10],ans;
bool cmp(int x,int y){return tm[x]<tm[y];}
bool check(int v,bool b){
	int lt=0,ln=0;
	for(int i=1;i<=n;++i) if(v<=a[id[i]]){
		if(b) printf("%d ",id[i]);
		lt+=tm[id[i]]; ++ln;
		if(lt>t) return 0; if(ln>=v) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&tm[i]); id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int p=1<<20;p;p/=2) ans+=check(ans+p,0)*p;
	printf("%d\n%d\n",ans,ans); if(ans) check(ans,1);
}