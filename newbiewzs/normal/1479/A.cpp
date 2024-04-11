#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1e5+55;
void clear(){
	cout.flush();
}
int ask(int x){
	int y;
	cout<<"? "<<x<<endl;
	cin>>y;
	clear();
	return y;
}
int n,vis[N];
void query(int x){
	if(!vis[x-1] and (x-1)>0){
		vis[x-1]=ask(x-1);
	}
	if(!vis[x+1] and x+1<=n){
		vis[x+1]=ask(x+1);
	}
	if(!vis[x]){
		vis[x]=ask(x);
	}
	if(vis[x]<vis[x-1] and vis[x]<vis[x+1]){
		cout<<"! "<<x;
		exit(0);
	}
}
#define mid ((l+r)>>1)
void solve(int l,int r){
	if(l==1 and r==5){
		new char;
	}
	query(mid);
	if(vis[mid-1]<vis[mid+1]){
		solve(l,mid-1);
	}
	else{
		solve(mid+1,r);
	}
}
int main(){
	cin>>n;
	vis[0]=vis[n+1]=1e9;
	solve(1,n);
	return 0;
}