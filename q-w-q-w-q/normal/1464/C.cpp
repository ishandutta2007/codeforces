#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long sum;
int a[100001];
char ch;
int main(){
	cin>>n>>sum;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=1<<(ch-'a');
	}
	sum=sum-a[n]+a[n-1];
	sort(a+1,a+n-1,greater<int>());
	for(int i=1;i<n-1;i++)
		if(sum<0) sum+=a[i];
		else sum-=a[i];
	puts(sum?"No":"Yes");
}