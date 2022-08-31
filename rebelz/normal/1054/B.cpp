#include<bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int now=-1;
	for(int i=1;i<=n;i++){
		if(a[i]>now+1){
			cout<<i<<endl;
			return 0;
		}
		now=max(now,a[i]);
	}
	cout<<-1<<endl;
	return 0;
}