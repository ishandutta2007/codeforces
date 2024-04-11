#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=(int)2e5+9;
struct node{
	int m,p;
}a[N];
int last[N];
bool cmp(node a,node b){
	if(a.m!=b.m)return a.m<b.m;
	return a.p<b.p;
}
int main()
{
	int T;
	scanf("%d",&T);
	priority_queue<int,vector<int>,greater<int>> PQ;
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d%d",&a[i].m,&a[i].p);
		while(!PQ.empty())PQ.pop(); 
		int tot=0;
		ll ans=0;
		sort(a,a+n,cmp);
		per(i,0,n){
			if(a[i].m>i+tot){
				int sz=PQ.size();
				if(a[i].m>i+tot+sz){
					ans+=a[i].p;
					tot++;
				}
				else{
					sz=a[i].m-i-tot;
					int cnt=0;
					ll sum=0;
					while(sz--){
						last[cnt]=PQ.top();
						PQ.pop();
						sum+=last[cnt++]; 
					}
					if(sum<=a[i].p){
						tot+=cnt;
						ans+=sum;
						PQ.push(a[i].p);
					}
					else{
						tot++;
						ans+=a[i].p;
						rep(i,0,cnt)PQ.push(last[i]);
					}
				}
			}
			else{
				PQ.push(a[i].p);
			}
		}
		printf("%lld\n",ans);
	}
}