#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10001];
int n,s=0;
int main(){
	cin>>n>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='8')s++;
	}
	cout<<min(s,n/11);
	return 0;
}