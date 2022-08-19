#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans;
int n;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int a[300005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		if(q.empty()||q.top().first>a[i]) q.push(make_pair(a[i],0));
		else{
			pair<int,int> p=q.top(); q.pop();
			ans+=a[i]-p.first;
			if(p.second>0) q.push(make_pair(p.first,0));
			q.push(make_pair(a[i],1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}