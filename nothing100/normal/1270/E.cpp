#include<bits/stdc++.h>
using namespace std;
int n,a[1010][2],f[1010],sum;
vector<int> ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
	int f=0;
	while (!f){
		sum=0;
		for (int i=0;i<n;i++)
		if ((a[i][0]+a[i][1])%2==0) sum++;
		if (sum==0||sum==n){
			for (int i=0;i<n;i++){
				int o,p;
				o=a[i][0];
				p=a[i][1];
				a[i][0]=(o-p-((o-p)&1))/2;
				a[i][1]=(o+p-((o+p)&1))/2;
			}
		}
		else f=1;
	}
	for (int i=0;i<n;i++){
		if ((a[i][0]+a[i][1])%2==0) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
}