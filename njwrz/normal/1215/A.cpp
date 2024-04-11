#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,m,a,b,nn;
	cin>>n>>m>>a>>b>>nn;
	int t=(n*(a-1))+(m*(b-1));
	if(nn<=t){
		cout<<0;
	}else{
		cout<<min(n+m,nn-t);
	}
	cout<<' ';
	if(a>b){
		swap(n,m);swap(a,b);
	}
	if(nn<=a*n){
		cout<<nn/a;
	}else cout<<min(m,(nn-a*n)/b)+n;
	return 0;
}