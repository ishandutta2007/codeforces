#include <bits/stdc++.h>
using namespace std;
bool check(int p){
	int a[10]={0};
	while(p!=0){
		a[p%10]++;
		p/=10;
	}
	for(int i=0;i<10;i++)if(a[i]>1)return 0;
	return 1;
}
int main(){
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		if(check(i)){
			cout<<i;return 0;
		}
	}
	cout<<-1;
	return 0;
}