#include<bits/stdc++.h>

using namespace std;

#define N 1200000

int n,m,a[N],sum;
vector<int> q;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<m;++i){
		scanf("%d",a+i);
		q.push_back((sum+=a[i])%n);
	}
	q.push_back(n);
	scanf("%d",a+m); sum+=a[m];
	printf("%d\n",(sum+n-1)/n);
	sort(q.begin(),q.end());
	q[m-1]=n;
	for (int i=m-1;i;--i) q[i]-=q[i-1];
	for (int i=0;i<m;++i) printf(i==m-1?"%d\n":"%d ",q[i]);
	int k=0;
	for (int i=1;i<=m;++i){
		while (a[i]>0){
			printf(k==m-1?"%d\n":"%d ",i);
			a[i]-=q[k++];
			k%=m;
		}
	}
	if (k) for (;k<m;++k) printf(k==m-1?"%d\n":"%d ",m);
	
	return 0;
}