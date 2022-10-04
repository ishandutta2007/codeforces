#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,q,Ans;
int a[100001],b[100001];
multiset<int> pq;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), pq.insert(a[i]);
	sort(a+1,a+n+1);
	multiset<int>::iterator it;
	F(i,1,n){
		it=pq.upper_bound(a[i]);
		if(it!=pq.end()) ++Ans,pq.erase(it);
		else break;
	} printf("%d",Ans);
	return 0;
}