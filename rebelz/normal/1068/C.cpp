#include<bits/stdc++.h>

using namespace std;

struct node{
	int x,y;
	node(int xx=0,int yy=0):x(xx),y(yy){}
};

int n,m;
int cnt[105],a[1005],b[1005],num[105],du[105];
vector<node> v[105];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		if(a[i]>b[i])
			swap(a[i],b[i]);
		du[b[i]]++;
	}
	for(int i=1;i<=n;i++)
		du[i]++;
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+du[i];
		for(int j=1;j<=du[i];j++)
			v[i].push_back(node(i,cnt[i-1]+j));
	}
	for(int i=1;i<=m;i++){
		v[a[i]].push_back(node(a[i],cnt[b[i]-1]+(++num[b[i]])));
	}
	for(int i=1;i<=n;i++){
		cout<<v[i].size()<<endl;
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j].x<<' '<<v[i][j].y<<endl;
		}
	}
	return 0;
}