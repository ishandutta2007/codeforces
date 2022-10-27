#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,k,a[500001],b[500001];
int l,r,mid,s;
ll sum,ans=1ll<<60;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	l=0,r=2e9;
	while(l<=r){
		mid=(0ll+l+r)>>1;
		while(!q.empty()) q.pop();
		sum=s=0;
		for(int i=n;i;i--){
			q.push(make_pair(b[i],1));
			if(mid-a[i]>=q.top().first){
				sum+=mid-a[i]-q.top().first;
				s+=q.top().second;
				q.pop(),q.push(make_pair(mid-a[i],0));
			}
		}
		if(s<k) l=mid+1;
		else ans=min(ans,1ll*s*mid-sum),r=mid-1;
	}
	cout<<ans;
}