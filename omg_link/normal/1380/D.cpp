#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n,m;
int a[MN+5],b[MN+5];
LL x,k,y,ans;

struct exception{
	const char *reason;
};
exception NoSolutionException(const char *reason = "null"){
	exception e;
	e.reason = reason;
	return e;
}

LL calc(int l,int r){
	int mx=0, len=r-l+1;
	LL x=::x, y=::y;
	for(int i=l;i<=r;i++)
		mx = std::max(mx,a[i]);
	if(mx<a[l-1] || mx<a[r+1]){
		x = std::min((LL)x,1ll*y*k);
		return (len/k)*x + (len%k)*y;
	}else{
		if(len<k) throw NoSolutionException("interval too short");
		LL res = 0;
		len -= k; res += x;
		x = std::min(x,y*k);
		res += (len/k)*x + (len%k)*y;
		return res;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%lld%lld%lld",&x,&k,&y);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	try{
		int j=1;
		for(int i=1;i<=m;i++,j++){
			int start = j;
			while(j<=n && a[j]!=b[i]) j++;
			if(j>n){
				throw NoSolutionException("fail to match the sequence");
				return 0;
			}
			ans += calc(start,j-1);
		}
		ans += calc(j,n);
		printf("%lld\n",ans);
	}catch(exception e){
		puts("-1");
	}
}