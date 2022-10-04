#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,q;
int a[100001],p[100001];
bool cmp(int i,int j){return a[i]==a[j]?i<j:a[i]>a[j];}

int main(){
	int x,y,z,w;
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d%d%d",&x,&y,&z,&w), a[i]=x+y+z+w, p[i]=i;
	sort(p+1,p+n+1,cmp);
	F(i,1,n) if(p[i]==1) return 0*printf("%d",i);
	return 0;
}