#include<iostream>
using namespace std;
int p[100001];
int main(){
	int n,i,a[100001];
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];p[i]=p[i-1]+a[i];
	}
	int q;
	cin>>q;
	for(i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<(p[y]-p[x-1])/10<<endl;
	}
	return 0;
}