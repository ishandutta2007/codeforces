#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=100005;
int ans[maxn];
bool use[maxn];
bool prime[maxn];
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)prime[i]=true;
	for(int i=2;i*i<=n;i++){
			if(!prime[i])continue;
			for(int j=i*2;j<=n;j+=i)prime[j]=false;
	}
	for(int i=n/2;i>2;i--){
			if(use[i])continue;
			if(!prime[i])continue;
			bool f=true;
			int tmp;
			for(int j=i;j<=n;j+=i){
					if(use[j])continue;
					if(f)tmp=j;
					else{
						 use[j]=use[tmp]=true;
						 ans[cnt++]=tmp;
						 ans[cnt++]=j;
					}
					f=!f;
			}
			if(!f&&tmp&1){use[ans[cnt-1]]=false;ans[cnt-1]=tmp;use[tmp]=true;}
	}
	bool f=true;
	int tmp;
	for(int j=2;j<=n;j+=2){
		if(use[j])continue;
		if(f)tmp=j;
		else{
			use[j]=use[tmp]=true;
			ans[cnt++]=tmp;
			ans[cnt++]=j;
		}
		f=!f;
	}
	printf("%d\n",cnt/2);
	for(int i=0;i<cnt;i+=2){
			printf("%d %d\n",ans[i],ans[i+1]);
	}
	//system("pause");
	return 0;
}