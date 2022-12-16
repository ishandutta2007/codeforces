#include <stdio.h>
#include <set>
typedef std::pair<int,int> pii;
std::set<pii,std::greater<pii>> a;
std::set<pii,std::less<pii>> b;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x<y){
			a.insert(pii(x,i));
		}else{
			b.insert(pii(x,i));
		}
	}
	if(a.size()>b.size()){
		printf("%u\n",(unsigned)a.size());
		for(auto p:a)
			printf("%d ",p.second);
	}else{
		printf("%u\n",(unsigned)b.size());
		for(auto p:b)
			printf("%d ",p.second);
	}
}