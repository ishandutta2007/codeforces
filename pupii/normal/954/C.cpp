// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<vector>
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
#define int long long
using namespace std;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
std::vector<int>fafa;
main(){
	#ifdef xzz
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	int n=gi(),lst=gi(),sb=-1;
	for(rg int i=2;i<=n;++i){
		int x=gi();
		if(x==lst){
		  	puts("NO");
		   	return 0;
		}
		if(abs(x-lst)>1){
			if(sb==-1)sb=abs(x-lst);
			else if(sb!=abs(x-lst)){
				puts("NO");
				return 0;
			}
		}else fafa.push_back(min(x,lst));
		lst=x;
	}
	if(~sb){
		for(rg int i=0;i<fafa.size();++i)if(fafa[i]%sb==0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	if(sb==-1)sb=1e9;
	printf("%lld %lld\n",(ll)1e9,sb);
	return 0;
}