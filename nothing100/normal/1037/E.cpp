#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k,res,deg[200020],ans[200020],a[200020][2];
vector<int> edge[200020];
queue<int> q;
void topu(){
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=0;i<edge[now].size();i++){
			if (deg[edge[now][i]]==k){
				q.push(edge[now][i]);
				res--;
			}
			deg[edge[now][i]]--;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		edge[a[i][0]].push_back(a[i][1]);
		edge[a[i][1]].push_back(a[i][0]);
		deg[a[i][0]]++;
		deg[a[i][1]]++;
	}
	res=n;
	for (int i=1;i<=n;i++)
	if (deg[i]<k){
		q.push(i); 
		res--;
	}
	for (int i=m-1;i>=0;i--){
		topu();
		ans[i]=res;
		if (deg[a[i][0]]>=k&&deg[a[i][1]]>=k){	
			if (deg[a[i][0]]==k) q.push(a[i][0]),res--;
			if (deg[a[i][1]]==k) q.push(a[i][1]),res--;
			deg[a[i][0]]--;
			deg[a[i][1]]--;
		}
		edge[a[i][0]].pop_back();
		edge[a[i][1]].pop_back();
	}
	for (int i=0;i<m;i++) printf("%d\n",ans[i]);
}