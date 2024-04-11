#include <cstdio>
#include <algorithm>
using namespace std;
bool cur;
int n,q,begin=1,end,typ,p,l,r,bit[100005];
inline void add(int x,int y){
	for (;x<=n;x+=x&-x) bit[x]+=y;
}
inline int Query(int x){
	int res=0;
	for (;x;x-=x&-x) res+=bit[x];
	return res;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i) add(i,1);
	end=n;
	for (int i=1;i<=q;++i){
		scanf("%d",&typ);
		if (typ==1){
			scanf("%d",&p);
			if (p<=(end-begin+1)/2)
				if (cur){
					p=end-p;
					for (int j=end;j>p;--j) add(2*p-j+1,Query(j)-Query(j-1));
					end=p;
				}
				else{
					p+=begin-1;
					for (int j=begin;j<=p;++j) add(2*p-j+1,Query(j)-Query(j-1));
					begin=p+1;
				}
			else{
				if (cur){
					p=end-p;
					for (int j=begin;j<=p;++j) add(2*p-j+1,Query(j)-Query(j-1));
					begin=p+1;
				}
				else{
					p+=begin-1;
					for (int j=end;j>p;--j) add(2*p-j+1,Query(j)-Query(j-1));
					end=p;
				}
				cur^=1;
			}
		}
		else{
			scanf("%d%d",&l,&r);
			if (cur) l=end-l,r=end-r;else l+=begin-1,r+=begin-1;
			if (l>r) swap(l,r);
			printf("%d\n",Query(r)-Query(l));
		}
	}
	return 0;
}