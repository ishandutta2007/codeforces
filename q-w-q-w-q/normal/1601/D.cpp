#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N=500005;
int n,d,s1,s2,ans;
int v[N],mx[N];

struct p1{
	int s,a;
	bool operator <(const p1 &j) const{return s<j.s;}
}a[N];

struct p2{
	int s,a;
	bool operator <(const p2 &j) const{return s<j.s;}
}b[N];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>d;
	while(n--){
		int s,t;
		cin>>s>>t;
		if(s<d)
			continue;
		if(s>=t)
			a[++s1]=p1{s,t};
		else
			b[++s2]=p2{s,t};
	}

	sort(a+1,a+s1+1),sort(b+1,b+s2+1);
	for(int i=1;i<=s1;i++)
		v[i]=a[i].s,mx[i]=max(mx[i-1],a[i].a);

	for(int i=1;i<=s2;i++){
		int p=lower_bound(v+1,v+s1+1,b[i].a)-v-1;
		if(mx[p]<=b[i].s)
			q.push(make_pair(b[i].a,b[i].s));
	}

	int m=0;
	while(!q.empty()){
		if(q.top().second<m){
			q.pop();
			continue;
		}

		m=q.top().first,ans++;
		q.pop();
	}

	cout<<s1+ans;
}