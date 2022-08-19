#include<bits/stdc++.h>

using namespace std;

int n;
char s[10],k;

int main(){
	cin>>n;
	int cnt=1;
	cout<<"0 0"<<endl;
	fflush(stdout);
	cin>>s;
	k=s[0];
	int l=1,r=1e9;
	while(l<r&&cnt<n){
		int mid=(l+r)/2;
		cnt++;
		cout<<mid<<' '<<0<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]==k)
			l=mid;
		else
			r=mid;
	}
	if(r==1e9)
		cout<<l<<' '<<1<<' '<<l-1<<' '<<3<<endl;
	else
		cout<<r<<' '<<1<<' '<<r+1<<' '<<3<<endl;
	return 0;
}