#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

struct node {
	int to[26],fail,len,pos,tot;
}t[N];
int cnt=1,cur=1,n=0,a[N],l=1,ans=0;
vector<int>d[N];
void extend(int x) {
	while (a[n-t[cur].len-1]!=a[n]) {
		cur=t[cur].fail;
//	cerr<<cur<<endl;
	}
	if (!t[cur].to[x]) {
		int u=t[cur].fail,v=++cnt;
		while (a[n-t[u].len-1]!=a[n]) {
			u=t[u].fail;
		}
		t[v].fail=t[u].to[x];
//		cerr<<cur<<endl;
//		cout<<v<<"->"<<t[v].fail<<"\n";
		t[cur].to[x]=v;
		t[v].len=t[cur].len+2;
	}
	cur=t[cur].to[x];
}
void cover(int x,int y) {
	if (x<=1) {
		return;
	}
	if (!t[x].pos) {
		ans+=!t[x].pos;
		t[t[x].fail].tot++;
	}
	if (t[x].pos<y) {
		t[x].pos=y;
		d[y-t[x].len+1].emplace_back(x);
	}
}
void push(int x) {
	a[++n]=x;
	extend(x);
	while (t[cur].len>n-l+1) {
		cur=t[cur].fail;
	}
//	cout<<"cur:"<<cur<<"\n";
	cover(cur,n);
}
void pop() {
	for (int x:d[l]) {
		if (t[x].pos-t[x].len+1!=l||t[x].tot) {
			continue;
		}
//		cout<<":"<<x<<"\n";
		cover(t[x].fail,t[x].pos);
		t[x].pos=0,ans--,t[t[x].fail].tot--;
	}
	l++;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	a[0]=-1;
	t[0].len=0,t[1].len=-1;
	t[0].fail=1,t[1].fail=0;
	int Q;
	cin>>Q;
	while (Q--) {
		string s;
		cin>>s;
		if (s=="push") {
			char x;
			cin>>x;
			push(x-'a');
		} else {
			pop();
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}