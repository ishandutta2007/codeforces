#include<bits/stdc++.h>
using namespace std;

const int M=105;
int n,sum;
bool flag[M];

struct node
{
	int a,id;
}a[M];

bool cmp(node a,node b)
{
	return a.a<b.a;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].a,a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n/2;i++)
		cout<<a[i].id<<' '<<a[n-i+1].id<<endl;
	return 0;
}