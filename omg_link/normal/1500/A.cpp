#include <stdio.h>
#include <vector>
#define MN 200000
#define MA 2500000
typedef std::pair<int,int> pii;

int n,a[MN+5];
int len[MA+5];
pii v[MA+5][4];

bool check(pii x,pii y){
	return x.first!=y.first&&x.first!=y.second&&x.second!=y.first&&x.second!=y.second;
}

bool check(int x){
	int s = len[x]-1;
	for(int i=0;i<s;i++){
		if(check(v[x][i],v[x][s])){
			puts("YES");
			printf("%d %d %d %d\n",v[x][i].first,v[x][s].second,v[x][s].first,v[x][i].second);
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>=a[j]){
				int x = a[i]-a[j];
				v[x][len[x]++] = pii(i,j);
				if(check(x)) return 0;
				if(len[x]==4) len[x] = 3;
			}else{
				int x = a[j]-a[i];
				v[x][len[x]++] = pii(j,i);
				if(check(x)) return 0;
				if(len[x]==4) len[x] = 3;
			}
		}
	}
	puts("NO");
	return 0;
}