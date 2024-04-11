#include <stdio.h>
#include <algorithm>
#include <set>
#define MN 200000
typedef long long LL;
typedef std::pair<int,int> pii;

int n,a[MN+5],nx[MN+5][30];
LL pre[MN+5];
std::set<pii> ans;

void calc(bool rv){
	for(int i=1;i<=n;i++)
		pre[i] = pre[i-1] + a[i];
	for(int j=0;j<30;j++)
		nx[n][j] = n+1;
	for(int i=n;i>=1;i--){
		bool flag = false;
		for(int j=29;j>=0;j--){
			if(a[i]&(1<<j))
				flag = true;
			if(flag)
				nx[i-1][j] = i;
			else
				nx[i-1][j] = nx[i][j];
		}
	}
	for(int l=1;l<=n-2;l++){
		LL sum = a[l+1];
		int r = l+2;
		int w = 1;
		while(r<=n&&w<30){
			if(sum==(a[r]^a[l])){
				if(rv){
					ans.insert(pii(n-r+1,n-l+1));
				}else{
					ans.insert(pii(l,r));
				}
			}
			while(sum>(1ll<<(w+1))) w++;
			if(w>=30) break;
			sum += pre[nx[r][w]-1]-pre[r-1];
			r = nx[r][w];
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	calc(false);
	std::reverse(a+1,a+1+n);
	calc(true);
	printf("%d\n",(int)ans.size());
}