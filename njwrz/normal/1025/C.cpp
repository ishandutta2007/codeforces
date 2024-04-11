#include<bits/stdc++.h>
using namespace std;
char a[200001];
int main(){
	int maxi=1,t=1;
	int q=0;
	while(cin>>a[q++]);
	q--;
	for(int i=q;i<q*2;i++)a[i]=a[i-q];
	for(int i=1;i<q*2;i++){
		if(a[i]!=a[i-1])t++;else t=1;
		maxi=max(maxi,t);
	}
	cout<<min(maxi,q);
	return 0;
}