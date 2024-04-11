#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],b[100001],p[100001]; long long A[100001];
priority_queue<int,vector<int>,greater<int> > pq;
bool cmp(int i,int j){return a[i]<a[j];}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i) scanf("%d",b+i);
	for(int i=1;i<=n;++i) p[i]=i;
	sort(p+1,p+n+1,cmp);
	long long S=0;
	for(int I=1;I<=n;++I){
		int i=p[I];
		A[i]=S+=b[i];
		pq.push(b[i]);
		if(pq.size()>k) S-=pq.top(), pq.pop();
	}
	for(int i=1;i<=n;++i) printf("%I64d ",A[i]);
	return 0;
}