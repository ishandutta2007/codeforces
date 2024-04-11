#include <bits/stdc++.h>
using namespace std;
int a[505][505],h[505];
int main(){
	int n,m,q,maxi,l;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		l=0;maxi=0;
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]){
				l++;
			}else l=0;
			maxi=max(maxi,l);
		}
		h[i]=maxi;
	}
	int x,y;
	for(int i=0;i<q;i++){
		cin>>x>>y;x--;y--;
		a[x][y]=1-a[x][y];
		l=0;maxi=0;
		for(int j=0;j<m;j++){
			if(a[x][j]){
				l++;
			}else l=0;
			maxi=max(maxi,l);
		}
		h[x]=maxi;
		maxi=0;
		for(int j=0;j<n;j++)maxi=max(maxi,h[j]);
		cout<<maxi<<'\n';
	}
	return 0;
}