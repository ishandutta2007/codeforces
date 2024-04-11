#include<bits/stdc++.h>
using namespace std;

const int M=105;
int n;
map<string,int> t;
struct node
{
	int num;
	string name,k;
}a[M];

bool cmp(node a,node b)
{
	return t[a.k]<t[b.k]||t[a.k]==t[b.k]&&a.num<b.num;
}

int main()
{
	t["rat"]=1,t["woman"]=t["child"]=2,t["man"]=3,t["captain"]=4;
	cin>>n;
	for (int i=1;i<=n;i++)
		a[i].num=i,cin>>a[i].name>>a[i].k;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
		cout<<a[i].name<<endl;
}