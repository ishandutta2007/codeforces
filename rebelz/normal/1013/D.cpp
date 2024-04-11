#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;
ll ans=0,n,m,q;
int f[500005];

int getfather(int v){
	if(f[v]==v)
		return v;
	return f[v]=getfather(f[v]);
}

int main(){
	cin>>n>>m>>q;
	int r,c;
	int cnt=n+m;
	for(int i=1;i<=n+m;i++)
		f[i]=i;
	for(int i=1;i<=q;i++){
		cin>>r>>c;
		c+=n;
		int fx=getfather(r),fy=getfather(c);
		if(fx!=fy){
			f[fx]=fy;
			cnt--;
		}
	}
	cout<<cnt-1<<endl;
	return 0;
}