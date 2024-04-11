#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define P(x,y) make_pair(x,y)

#define N 4000

int t,n,m,p,a[N];

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&n,&m,&p);
		for (int i=1;i<=n;++i) scanf("%d",a+i);
		int ans=0;
		p=min(p,m-1);
		for (int i=0;i<=p;++i){
			int tmp=0x3f3f3f3f;
			for (int j=0;j<=m-p-1;++j)
				tmp=min(tmp,max(a[i+j+1],a[n-(m-i-j-1)]));
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}