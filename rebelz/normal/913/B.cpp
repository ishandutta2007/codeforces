#include<iostream>

using namespace std;

int n,tot=0;
int v[10005],next[10005],h[10005];

void addedge(int x,int y){
	v[++tot]=y; next[tot]=h[x]; h[x]=tot;
}

int dfs(int u){
	int cnt=0,t;
	bool flag=true;
	for(int p=h[u];p;p=next[p]){
		flag=false;
		t=dfs(v[p]);
		if(t==2)
			cnt++;
		else if(t==0)
			return false;
	}
	if(flag)
		return 2;
	if(cnt<3)
		return 0;
	return 1;
}

int main(){
	cin>>n;
	int a;
	for(int i=2;i<=n;i++){
		cin>>a;
		addedge(a,i);
	}
	if(dfs(1)!=0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}