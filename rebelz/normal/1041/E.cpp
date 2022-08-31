#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,x,y,cnt;
int k[1005],t[1005];
bool vis[1005],c[1005][1005];

int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y; if(x>y)swap(x,y);
		if(y!=n){
			cout<<"NO"<<endl;
			return 0;
		}
		if(!vis[x])
			vis[x]=true,c[x][n]=true,k[x]=x;
		else
			t[++cnt]=x;
	}
	for(int i=1;i<=cnt;i++){
		bool flag=true;
		for(int j=t[i];j>=1;j--){
			if(!vis[j]){
				vis[j]=true,c[j][n]=true,c[k[t[i]]][n]=false,c[j][k[t[i]]]=true;
				k[t[i]]=j,flag=false;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(c[i][j])
				cout<<i<<' '<<j<<endl;
	return 0;
}