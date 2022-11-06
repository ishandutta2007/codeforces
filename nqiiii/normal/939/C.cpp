#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,ans,maxv,id;
ll s[400000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&s[i]); s[i+n]=s[i];
	}
	for(int i=1;i<=n*2;++i) s[i]+=s[i-1];
	int l,r; scanf("%d%d",&l,&r); --r; l+=n; r+=n;
	for(int i=1;i<=n;++i){
		int nowl=l-i+1;
		int nowr=r-i+1;
		ans=s[nowr]-s[nowl-1];
		if(ans>maxv) maxv=ans,id=i;
	}
	printf("%d",id);
}