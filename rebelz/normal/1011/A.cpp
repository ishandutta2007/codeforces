#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int n,k;
int a[100005];
char s[100005];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		a[i]=s[i]-'a'+1;
	}
	sort(a+1,a+n+1);
	a[0]=-1;
	int ans=0,last=-1;
	for(int i=1;i<=n&&k>0;i++)
		if(a[i]-last>=2)
			ans+=a[i],k--,last=a[i];
	if(k>0)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}