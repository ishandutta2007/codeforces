#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a[4];
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4,greater<int>());
	if(a[1]>a[2]+a[3]+1){
		puts("No");
	}else puts("Yes");
}
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	return 0;
}