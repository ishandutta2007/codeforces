#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int inf=1000000000;
int a[5010],b[5010];
vector<pair<pii,pii>> V;
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)b[i]=inf;
	for(int i=0;i<m;i++){
		int t,l,r,x;scanf("%d%d%d%d",&t,&l,&r,&x);
		l--;
		V.push_back({{t,x},{l,r}});
		if(t==1){
			for(int j=l;j<r;j++)a[j]+=x;
		}
		else{
			for(int j=l;j<r;j++)b[j]=min(b[j],x-a[j]);
		}
	}
	for(int i=0;i<n;i++)a[i]=0;
	for(auto &e:V){
		int t,l,r,x;tie(t,x)=e.first;tie(l,r)=e.second;
		if(t==1){
			for(int j=l;j<r;j++)a[j]+=x;
		}
		else{
			int Max=-inf-inf;
			for(int j=l;j<r;j++){
				Max=max(Max,a[j]+b[j]);
			}
			if(Max!=x)return puts("NO"),0;
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)printf("%d ",b[i]);puts("");
}