#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e3+5;

template<typename T>
bool ckmx(T &x,T y) {
	if (x<y) {
		x=y;
		return true;
	}
	return false;
}
struct node {
	int son[12],fail,val;
}t[N];
int cnt=0;
void insert(string s,int x) {
	int now=0;
	for (char c:s) {
		int to=c-'a';
		if (!t[now].son[to]) {
			t[now].son[to]=++cnt;
		}
		now=t[now].son[to];
	}
	t[now].val+=x;
	cerr<<s<<':'<<x<<endl;
}
void build() {
	queue<int>q;
	for (int i=0;i<12;i++) {
		if (t[0].son[i]) {
			q.push(t[0].son[i]);
		}
	}
	while (!q.empty()) {
		int now=q.front(); q.pop();
		for (int i=0;i<12;i++) {
			if (t[now].son[i]) {
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q.push(t[now].son[i]);
			} else {
				t[now].son[i]=t[t[now].fail].son[i];
			}
		}
		t[now].val+=t[t[now].fail].val;
	}
}
int n,dp[N][1<<12];
pair<int,int>from[N][1<<12];
void work() {
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;
	cin>>n;
	for (int T=1;T<=n;T++) {
		int x;
		string s,t;
		cin>>x>>s;
		vector<vector<int>>e(12,vector<int>(12));
		for (int i=0;i+1<(int)s.size();i++) {
			e[s[i]-'a'][s[i+1]-'a']=1;
			e[s[i+1]-'a'][s[i]-'a']=1;
		}
		auto check=[&]()->bool {
			int tot[3]={},deg[12]={};
			for (int i=0;i<12;i++) {
				for (int j=0;j<12;j++) {
					deg[i]+=e[i][j];
				}
				if (deg[i]>2) {
					return false;
				}
				tot[deg[i]]++;
			}
			if (tot[1]!=2) {
				return false;
			}
			bool vis[12]={};
			auto dfs=[&](auto &self,int now,int father)->bool {
				t+=char(now+'a');
				vis[now]=1;
				for (int i=0;i<12;i++) {
					if (e[now][i]) {
						if (vis[i]) {
							if (i==father) {
								continue;
							}
							return false;
						} else {
							if (!self(self,i,now)) {
								return false;
							}
						}
					}
				}
				return true;
			};
			for (int i=0;i<12;i++) {
				if (deg[i]==1) {
					return dfs(dfs,i,-1);
				}
			}
			assert(false);
		};
		if (check()) {
			insert(t,x);
			reverse(t.begin(),t.end());
			insert(t,x);
		}
	}
	build();
	int ans=-1,now=-1,state=-1;
	for (int S=0;S<(1<<12);S++) {
		for (int i=0;i<=cnt;i++) {
			if (dp[i][S]<0) {
				continue;
			}
			if (S==(1<<12)-1&&ckmx(ans,dp[i][S])) {
				now=i,state=S;
			}
			for (int j=0;j<12;j++) {
				if (S>>j&1) {
					continue;
				}
				if (ckmx(dp[t[i].son[j]][S|1<<j],dp[i][S]+t[t[i].son[j]].val)) {
					from[t[i].son[j]][S|1<<j]=make_pair(i,j);
				}
			}
		}
	}
	string s;
	while (state) {
		auto [x,y]=from[now][state];
		s+=char(y+'a');
		state^=1<<y;
		now=x;
	}
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}