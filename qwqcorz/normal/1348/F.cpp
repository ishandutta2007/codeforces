#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,p[N],np[N];
struct node {
	int l,r,p,id;
}a[N];
vector<int>b[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].l>>a[i].r;
		a[i].id=i;
	}
	sort(a+1,a+1+n,[&](node x,node y){
		return x.l<y.l;
	});
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
	for (int i=1,j=1;i<=n;i++) {
		while (j<=n&&a[j].l<=i) {
			q1.push({a[j].r,j});
			j++;
		}
		int id=q1.top().second;
		q1.pop();
		a[id].p=i;
		p[a[id].id]=i;
		np[i]=a[id].id;
	}
	for (int i=1;i<=n;i++) {
		b[a[i].l].push_back(a[i].p);
	}
	sort(a+1,a+1+n,[&](node x,node y){
		return x.id<y.id;
	});
	priority_queue<int,vector<int>,greater<int>>q2;
	for (int i=1;i<=n;i++) {
		for (int j:b[i]) {
			q2.push(j);
		}
		while (!q2.empty()&&q2.top()<=i) {
			q2.pop();
		}
		if (!q2.empty()&&q2.top()<=a[np[i]].r) {
			int x=i,y=q2.top();
			cout<<"NO\n";
			for (int j=1;j<=n;j++) {
				cout<<p[j]<<" \n"[j==n];
			}
			swap(p[np[x]],p[np[y]]);
			for (int j=1;j<=n;j++) {
				cout<<p[j]<<" \n"[j==n];
			}
			return 0;
		}
	}
	cout<<"YES\n";
	for (int i=1;i<=n;i++) {
		cout<<p[i]<<" \n"[i==n];
	}
	
	return 0;
}