#include<cstdio>
#include<map>
#include<algorithm>
#define N 200010
using namespace std;
int n,m,i,j,a[N],A,B,t,s,p,ans;
map<int,int>mp;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mp[a[i]]){a[i]=0;continue;}
		mp[a[i]]=1;
		if(a[i]%2==1)A++;else B++;
	}
	if(A>B)t=1;else t=0,swap(A,B);
	if(A>n/2)
		for(i=1;i<=n&&A>n/2;i++)
			if(a[i]%2==t)a[i]=0,A--;
	p=1;
	for(i=1;i<=n;i++)
	if(a[i]==0){
		for(;p<=m&&mp[p]||!((p%2==t&&A<n/2)||(p%2!=t&&B<n/2));p++);
		if(p<=m)mp[p]=1,a[i]=p,(p%2==t?A++:B++),ans++;
	}
	if(A+B<n){puts("-1");return 0;}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
}