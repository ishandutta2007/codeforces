#include<bits/stdc++.h>

using namespace std;

int n,x;
int a[200005],b[200005],c[200005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		c[x]=i;
	}
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		b[i]=c[b[i]];
	int maxa=0;
	for(int i=1;i<=n;i++){
		cout<<max(0,b[i]-maxa)<<' ';
		maxa=max(maxa,b[i]);
	}
	return 0;
}