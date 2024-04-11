#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=200005;
int n;
map<int,vector<int> > V;
pair<int,int> a[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].first);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].second);
	for (int i=1;i<=n;i++) V[a[i].first].pb(a[i].second);
	LL Cs=0,ans=0;
	multiset<int> cur;
	for (map<int,vector<int> > ::iterator it=V.begin();it!=V.end();it++){
		vector<int> tmp=it->second;
		int curt=it->first;
		it++;
		int Nxt;
		if (it==V.end()) Nxt=2e9;
		else Nxt=it->first;
		it--;
		int cnt=Nxt-curt;
		for (int i=0;i<tmp.size();i++) cur.insert(tmp[i]),Cs+=tmp[i];
		while (!cur.empty() && cnt){
			int v=*cur.rbegin();Cs-=v;
			ans+=Cs;
			cur.erase(cur.find(v));cnt--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}