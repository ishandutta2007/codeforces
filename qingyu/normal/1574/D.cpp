#include <bits/stdc++.h>
using namespace std;
const int N=2e5+50;

int n,m;
int c[N],a[15][N];
mt19937 _s(chrono::steady_clock::now().time_since_epoch().count());
uint64_t bs;

struct plan{
	int c[11];
	plan(){
		memset(c,0,sizeof c);
	}
	bool operator<(const plan &y)const{
		for(int i=0;i<10;++i)
			if(c[i]<y.c[i]){
				return true;
			}else if(c[i]>y.c[i]){
				return false;
			}
		return false;
	}
	bool operator==(const plan &y)const{
		for(int i=0;i<10;++i)
			if(c[i]!=y.c[i])return false;
		return true;
	}
};
set<plan> s;
set<int> t;

uint64_t sb(const plan&o){
	uint64_t h=0;
	for(int i=0;i<n;++i)h=h*bs+o.c[i];
	return h;
}

int main() {
	bs=_s()|3;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>c[i];
		for(int j=1;j<=c[i];++j)cin>>a[i][j];
		reverse(a[i]+1,a[i]+c[i]+1);
	}
	cin>>m;
	for(int i=0;i<m;++i){
		plan a;
		for(int j=0;j<n;++j){
			cin>>a.c[j];
			a.c[j]=c[j]-a.c[j]+1;
		}
		s.insert(a);
		assert(s.count(a));
	}
	long long ans=0;
	queue<plan> q;
	plan o,result;
	for(int i=0;i<n;++i)o.c[i]=1;
	q.emplace(o);
	while (!q.empty()){
		auto p=q.front();q.pop();
		if(s.count(p)){
			for(int i=0;i<n;++i)
				if(p.c[i]<c[i]){
					plan p2;
					for(int k=0;k<n;++k)p2.c[k]=p.c[k];
					++p2.c[i];
					auto hsr = sb(p2);
					if(!t.count(hsr))
					{
						q.emplace(p2);
						t.insert(hsr);
					}
				}
		}
		else{
			long long r=0;
			for(int i=0;i<n;++i)r+=a[i][p.c[i]];
			if(ans<r){
			ans=max(ans,r);
			result=p;
			}
		}
	}
	//cout<<ans<<'\n';
	for(int i=0;i<n;++i)cout<<c[i]+1-result.c[i]<<" ";
}