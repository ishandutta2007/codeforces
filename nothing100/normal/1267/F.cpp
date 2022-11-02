#include<bits/stdc++.h>
using namespace std;
int n,m,k[2];
int a[2][200010],deg[200020];
set<int> s;
int main(){
	scanf("%d%d%d%d",&n,&m,&k[0],&k[1]);
	for (int i=1;i<=k[0];i++){
		scanf("%d",&a[0][i]);
		deg[a[0][i]]++;
	}
	for (int i=1;i<=k[1];i++){
		scanf("%d",&a[1][i]);
		deg[a[1][i]]++;
	}
	deg[a[0][k[0]]]=m;
	deg[a[1][k[1]]]=n;
	int tail[2];
	tail[0]=tail[1]=1;
	if (k[0]>=m||k[1]>=n){
		printf("No\n");
	}
	else{
		printf("Yes\n");
		printf("%d %d\n",a[0][k[0]],a[1][k[1]]);
		for (int i=1;i<=n+m;i++)
		if (deg[i]==0) s.insert(i);
		while (!s.empty()){
			int now=*s.begin();
			s.erase(now);
			int kd=0;
			if (now<=n) kd=1;
			printf("%d %d\n",now,a[kd][tail[kd]]);
			deg[a[kd][tail[kd]]]--;
			if (deg[a[kd][tail[kd]]]==0) s.insert(a[kd][tail[kd]]);
			tail[kd]=min(tail[kd]+1,k[kd]);
		}
	}
}