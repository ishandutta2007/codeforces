#include <bits/stdc++.h>
using namespace std;
int main(){
	char a[200005];int la=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[++la];
		if(i<n)cin>>a[++la],i++;else break;
		while(a[la]==a[la-1]&&i<n)cin>>a[la],i++;
	}
	if(a[la]==a[la-1])la--;
	if(la%2==1)la--;
	cout<<n-la<<'\n';
	for(int i=1;i<=la;i++)cout<<a[i];
	return 0;
}