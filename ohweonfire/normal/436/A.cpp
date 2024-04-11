#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=2005;
struct candy{
	   int t,h,m;
}a[maxn];

int n;
bool use[maxn];
int gre1(int x){
	memset(use,0,sizeof(use));
	priority_queue<int> cf[2];
	for(int i=0;i<n;i++)if(a[i].h<=x){cf[a[i].t].push(a[i].m);use[i]=true;}
	int now=0,cnt=0;
	while(cf[now].size()){
						  int tmp=cf[now].top();
						  cf[now].pop();
						  x+=tmp;
						  cnt++;
						  now=1-now;
						  for(int i=0;i<n;i++)
						  if(!use[i]&&a[i].h<=x){cf[a[i].t].push(a[i].m);use[i]=true;}
	}
	return cnt;
}
int gre2(int x){
	memset(use,0,sizeof(use));
	priority_queue<int> cf[2];
	for(int i=0;i<n;i++)if(a[i].h<=x){cf[a[i].t].push(a[i].m);use[i]=true;}
	int now=1,cnt=0;
	while(cf[now].size()){
						  int tmp=cf[now].top();
						  cf[now].pop();
						  x+=tmp;
						  cnt++;
						  now=1-now;
						  for(int i=0;i<n;i++)
						  if(!use[i]&&a[i].h<=x){cf[a[i].t].push(a[i].m);use[i]=true;}
						  
	}
	return cnt;
}
int main(){
	int x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].t,&a[i].h,&a[i].m);
	}
	printf("%d\n",max(gre1(x),gre2(x)));
	//system("pause");
	return 0;
}