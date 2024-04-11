#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
const int maxn=302;
vector<pair<int,int> > ans;
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
	 		if(i&1==1)for(int j=1;j<=m;j++){ans.push_back(make_pair(i,j));}
			else for(int j=m;j>=1;j--){ans.push_back(make_pair(i,j));}
	}
	int id=0;
	for(int i=1;i<k;i++){
			printf("2 %d %d ",ans[id].first,ans[id].second);
			id++;
			printf("%d %d\n",ans[id].first,ans[id].second);
			id++;
	}
	printf("%d ",n*m-2*k+2);
	for(;id<ans.size();id++)printf("%d %d ",ans[id].first,ans[id].second);
	//system("pause");
	return 0;
}