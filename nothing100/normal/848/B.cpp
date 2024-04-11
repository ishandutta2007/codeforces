#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
struct ques{
	int a[4];
}q[100010];
int ans[100010][2],n,w,h;
deque<int>line;
deque<int> id;
int cmp(ques x,ques y){
	if ((x.a[1]-x.a[2])==(y.a[1]-y.a[2])){
		if (x.a[0]==y.a[0]){
			return x.a[2]<y.a[2];
		}
		return x.a[0]<y.a[0];
	}
	return (x.a[1]-x.a[2])<(y.a[1]-y.a[2]);
}
int main() {
	scanf("%d%d%d",&n,&w,&h);
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&q[i].a[0],&q[i].a[1],&q[i].a[2]);
		q[i].a[3]=i;
	}
	sort(q,q+n,cmp);
	//for (int i=0;i<n;i++) printf("%d %d %d %d\n",q[i].a[0],q[i].a[1],q[i].a[2],q[i].a[3]);
	for (int i=0;i<n;i++){
		if (i&&((q[i].a[1]-q[i].a[2])!=(q[i-1].a[1]-q[i-1].a[2]))){
			while (!line.empty()){
				ans[id.back()][0]=line.back();
				ans[id.back()][1]=h;
				id.pop_back();
				line.pop_back();
			}
		}
		if (q[i].a[0]==1){
			line.push_back(q[i].a[1]);
			id.push_back(q[i].a[3]);
		}
		else{
			if (line.empty()){
				ans[q[i].a[3]][0]=w;
				ans[q[i].a[3]][1]=q[i].a[1];
			}
			else{
				ans[id.back()][0]=w;
				ans[id.back()][1]=q[i].a[1];
				id.pop_back();
				id.push_front(q[i].a[3]);
			}
		}
	}
	while (!line.empty()){
				ans[id.back()][0]=line.back();
				ans[id.back()][1]=h;
				id.pop_back();
				line.pop_back();
			}
	for (int i=0;i<n;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}