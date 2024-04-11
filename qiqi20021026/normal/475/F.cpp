#include<bits/stdc++.h>

using namespace std;

#define se set<pair<int,int> >
#define N 120000
#define P(x,y) make_pair(x,y)
#define ff first
#define ss second

int n,ans,x[N],y[N];
se s1,s2;

void solve(se &s1,se &s2){
	se::iterator i1=s1.begin(),i2=--s1.end(),j1=s2.begin(),j2=--s2.end();
	for (;i1!=s1.end()&&j1!=s2.end();++i1,++j1,--i2,--j2){
		se::iterator k=i1; ++k;
		if (k==s1.end()) break;
		if ((*i1).ff>=(*i2).ff&&(*j1).ff>=(*j2).ff) break;
		if ((*i1).ff+1<(*k).ff){
			se ss1,ss2;
			for (se::iterator t=s1.begin();t!=k;){
				int u=(*t).ss; ++t;
				s1.erase(P(x[u],u)); ss1.insert(P(x[u],u));
  				s2.erase(P(y[u],u)); ss2.insert(P(y[u],u));
			}
			++ans; solve(ss1,ss2); solve(s1,s2);
			return;
		}
		k=i2; --k;
		if ((*i2).ff-1>(*k).ff){
			se ss1,ss2;
			for (se::iterator t=--s1.end();t!=k;){
				int u=(*t).ss; --t;
				s1.erase(P(x[u],u)); ss1.insert(P(x[u],u));
				s2.erase(P(y[u],u)); ss2.insert(P(y[u],u));
			}
			++ans; solve(ss1,ss2); solve(s1,s2);
			return;
		}
		k=j1; ++k;
		if ((*j1).ff+1<(*k).ff){
			se ss1,ss2;
			for (se::iterator t=s2.begin();t!=k;){
				int u=(*t).ss; ++t;
				s1.erase(P(x[u],u)); ss1.insert(P(x[u],u));
				s2.erase(P(y[u],u)); ss2.insert(P(y[u],u));
			}
			++ans; solve(ss1,ss2); solve(s1,s2);
			return;
		}
		k=j2; --k;
		if ((*j2).ff-1>(*k).ff){
			se ss1,ss2;
			for (se::iterator t=--s2.end();t!=k;){
				int u=(*t).ss; --t;
				s1.erase(P(x[u],u)); ss1.insert(P(x[u],u));
				s2.erase(P(y[u],u)); ss2.insert(P(y[u],u));
			}
			++ans; solve(ss1,ss2); solve(s1,s2);
			return;
		}
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		s1.insert(P(x[i],i));
		s2.insert(P(y[i],i));
	}
	ans=1; solve(s1,s2);
	printf("%d\n",ans);
	
	return 0;
}