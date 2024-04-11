#include<bits/stdc++.h>
using namespace std;
bool a[1001][1001],b[1001][1001];
int fxi[8]={0,0,0,1,1,2,2,2},fxj[8]={0,1,2,0,2,0,1,2};
int main(){
	int n,m,i,j,k;char x;bool f;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>x;
			if(x=='#')a[i][j]=1;
		}
	}
	for(i=0;i<n-2;i++){
		for(j=0;j<m-2;j++){
			f=1;
			for(k=0;k<8;k++){
				if(!a[i+fxi[k]][j+fxj[k]])f=0;
			}
			if(f){
				for(k=0;k<8;k++){
					b[i+fxi[k]][j+fxj[k]]=1;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]!=b[i][j]){
				cout<<"NO";return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}