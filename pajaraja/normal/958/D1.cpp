#include <bits/stdc++.h>
using namespace std;
float arr[200007];
map<float,int> cnt;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		char ch;
		cin>>ch;
		scanf("%d+%d)/%d",&a,&b,&c);
		arr[i]=(a+b+0.0)/(c+0.0);
		cnt[arr[i]]++;
	}
	for(int i=0;i<n;i++) printf("%d ",cnt[arr[i]]);
}