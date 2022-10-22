#include <bits/stdc++.h>
using namespace std;
int x[200005],y[200005];
string a,b;
int main(){
	cin>>a>>b;
	int la=a.size(),lb=b.size();
	int l=0;
	for(int i=0;i<lb;i++){
		while(a[l]!=b[i]){
			l++;
		}
		x[i+1]=l;
		l++;
	}
	l=la-1;
	for(int i=lb-1;i>=0;i--){
		while(a[l]!=b[i]){
			l--;
		}
		y[i+1]=l;
		l--;
	}
	int maxi=max(y[1],la-x[lb]-1);
	for(int i=1;i<lb;i++){
		maxi=max(maxi,y[i+1]-x[i]-1);
	}
	cout<<maxi;
	return 0;
}