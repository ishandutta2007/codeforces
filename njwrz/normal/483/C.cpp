#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int f=n-1,s=1;
	cout<<s<<' ';
	for(int i=1;i<k;i++){
		cout<<s+f<<' ';s+=f;
		if(f>0)f=-(f-1);else f=-(f+1);
	}
	if(f>0){
		for(int i=n-k;i>=1;i--)cout<<++s<<' ';
	}else{
		for(int i=n-k;i>=1;i--)cout<<--s<<' ';
	}
	return 0;
}