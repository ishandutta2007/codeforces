#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
using namespace std;

int n,A,B;
int a[100001],b[100001];
priority_queue<int> pq;
ll Ans=0;

int main() {
	scanf("%d%d%d",&n,&A,&B);
	A+=B;
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) scanf("%d",b+i);
	F(i,1,n) a[i]=abs(a[i]-b[i]), pq.push(a[i]);
	F(i,1,A) {
		int x=pq.top();
		pq.pop();
		if(x>0) pq.push(x-1);
		else pq.push(1);
	}
	int x;
	F(i,1,n) x=pq.top(), Ans+=(ll)x*x, pq.pop();
	printf("%lld",Ans);
	return 0;
}