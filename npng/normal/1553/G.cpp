#include <cstdio>
#include <algorithm>
const int Maxn=150000;
const int Maxv=1000001;
int n,q;
int a[Maxn+5];
bool np[Maxv+5];
int id[Maxv+5];
int p[Maxv+5],min_p[Maxv+5],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxv;i++){
		if(!np[i]){
			p[++p_len]=i;
			id[i]=p_len;
			min_p[i]=i;
		}
		for(int j=1,x;1ll*i*p[j]<=Maxv;j++){
			x=i*p[j];
			np[x]=1;
			min_p[x]=p[j];
			if(i%p[j]==0){
				break;
			}
		}
	}
}
namespace DSU{
	int fa[Maxv+Maxn+5];
	void init(){
		for(int i=1;i<=n+p_len;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x;
	}
}
std::pair<int,int> lis[Maxn*180+5];
int lis_len;
int p_lis[25],p_lis_len;
int main(){
	init();
	scanf("%d%d",&n,&q);
	DSU::init();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int x=a[i];
		while(x>1){
			DSU::merge(i,id[min_p[x]]+n);
			x/=min_p[x];
		}
	}
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		p_lis_len=0;
		while(x>1){
			int y=min_p[x];
			p_lis[++p_lis_len]=min_p[x];
			lis[++lis_len]=std::make_pair(DSU::find(i),DSU::find(id[y]+n));
			x/=min_p[x];
		}
		std::sort(p_lis+1,p_lis+1+p_lis_len);
		p_lis_len=std::unique(p_lis+1,p_lis+1+p_lis_len)-p_lis-1;
		for(int j=1;j<=p_lis_len;j++){
			for(int k=j+1;k<=p_lis_len;k++){
				lis[++lis_len]=std::make_pair(DSU::find(id[p_lis[j]]+n),DSU::find(id[p_lis[k]]+n));
			}
		}
	}
	std::sort(lis+1,lis+1+lis_len);
	lis_len=std::unique(lis+1,lis+1+lis_len)-lis-1;
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u=DSU::find(u),v=DSU::find(v);
		if(u==v){
			puts("0");
		}
		else{
			int pos=std::lower_bound(lis+1,lis+1+lis_len,std::make_pair(u,v))-lis;
			if(pos>lis_len||lis[pos]!=std::make_pair(u,v)){
				pos=std::lower_bound(lis+1,lis+1+lis_len,std::make_pair(v,u))-lis;
				if(pos>lis_len||lis[pos]!=std::make_pair(v,u)){
					puts("2");
				}
				else{
					puts("1");
				}
			}
			else{
				puts("1");
			}
		}
	}
	return 0;
}