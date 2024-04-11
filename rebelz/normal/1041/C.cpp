#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;

struct node{
	int id;
	ll val;
	node(int ii=0,ll vv=0):id(ii),val(vv){}
	bool operator<(const node c)const{
		return val<c.val;
	}
	bool operator>(const node c)const{
		return val>c.val;
	}
}k[200005];

priority_queue<node,vector<node>,greater<node> > q;
ll n,m,d;
ll ans[200005];

int main(){
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++){
		cin>>k[i].val;
		k[i].id=i;
	}
	sort(k+1,k+n+1);
	q.push(node(0,1<<30));
	int cnt=0;
	for(int i=1;i<=n;i++){
		node t=q.top();
		if(t.val+d>=k[i].val){
			q.push(node(++cnt,k[i].val));
			ans[k[i].id]=cnt;
		}
		else{
			q.pop();
			q.push(node(t.id,k[i].val));
			ans[k[i].id]=t.id;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}