#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,num[10]={0},ans=0;
	char s[105];
	cin>>n;
	scanf("%s",s);
	for(int i=0;i<n;i++)
	num[s[i]-48]++;
	ans=n/11;
	ans=ans<num[8]?ans:num[8];
	num[8]-=ans;
	cout<<ans;
 }