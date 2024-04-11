#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int main(){
	int b,g,n;
	cin>>b>>g>>n;
	int ans=0;
	for(int i=0;i<=b;i++){
		int t=n-i;
		if(t>=0&&t<=g)ans++;
	}
	cout<<ans;
	return 0;
}