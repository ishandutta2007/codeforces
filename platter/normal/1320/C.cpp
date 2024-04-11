#include <bits/stdc++.h>
using namespace std;

const int sz=1048576;
long long seg[sz*2];
long long lazy[sz*2];
const long long INF=1e12;

void propagate(int node) {
    if (lazy[node]!=0) {
    	seg[node]+=lazy[node];
    	if (node<sz) {
    		lazy[node*2]+=lazy[node];
    		lazy[node*2+1]+=lazy[node];
    	}
    	lazy[node]=0;
    }
}

long long sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
	propagate(node);
	if (r<nodel||l>noder) {
		return -INF;
	}
	if (l<=nodel&&noder<=r) {
		return seg[node];
	}
	int mid=(nodel+noder)/2;
	return max(sum(l,r,node*2,nodel,mid),sum(l,r,node*2+1,mid+1,noder));
}

void update(int l,int r,long long val,int node=1,int nodel=0,int noder=sz-1) {
	propagate(node);
	if (r<nodel||l>noder) {
		return;
	}
	if (l<=nodel&&noder<=r) {
		lazy[node]+=val;
		propagate(node);
		return;
	}
	int mid=(nodel+noder)/2;
	update(l,r,val,node*2,nodel,mid);
	update(l,r,val,node*2+1,mid+1,noder);
	seg[node]=max(seg[node*2],seg[node*2+1]);
}

void construct() {
	for(int i=sz-1;i>0;i--) {
		seg[i]=max(seg[i*2],seg[i*2+1]);
	}
	for(int i=1;i<sz*2;i++) {
	    lazy[i]=0;
	}
}

int n,m,p;
typedef pair<long long,long long> P;
typedef pair<P,long long> Pl;
vector<P> attack;
vector<P> defen;
vector<Pl> mon;
vector<P> at;
vector<P> de;

bool comp(P a,P b) {
	if (a.first==b.first) {
		return a.second<b.second;
	}
	return a.first>b.first;
}

int main(void) {
	scanf("%d %d %d\n",&n,&m,&p);
	for(int i=0;i<n;i++) {
		long long x,y;
		scanf("%lld %lld\n",&x,&y);
		attack.push_back(P(x,y));
	}
	for(int i=0;i<m;i++) {
		long long x,y;
		scanf("%lld %lld\n",&x,&y);
		defen.push_back(P(x,y));
	}
	sort(attack.begin(),attack.end(),comp);
	sort(defen.begin(),defen.end(),comp);
	long long mini=INF;
	for(int i=0;i<n;i++) {
		if (mini>attack[i].second) {
			at.push_back(attack[i]);
		}
		mini=min(mini,attack[i].second);
	}
	reverse(at.begin(),at.end());
	mini=INF;
	for(int i=0;i<m;i++) {
		if (mini>defen[i].second) {
			de.push_back(defen[i]);
		}
		mini=min(mini,defen[i].second);
	}
	reverse(de.begin(),de.end());
	for(int i=0;i<de.size();i++) {
		if (i==0) {
			for(int j=0;j<de[0].first;j++) {
				seg[sz+j]=-de[0].second;
			}
		}
		else {
			for(int j=de[i-1].first;j<de[i].first;j++) {
				seg[sz+j]-=de[i].second;
			}
		}
	}
	for(int i=de[de.size()-1].first;i<sz;i++) {
		seg[sz+i]=-INF;
	}
	construct();
	for(int i=0;i<p;i++) {
		long long x,y,z;
		scanf("%lld %lld %lld\n",&x,&y,&z);
		mon.push_back(Pl(P(x,y),z));
	}
	sort(mon.begin(),mon.end());
	int mind=0;
	long long ret=-INF;
	for(int i=0;i<at.size();i++) {
		while (mind<p&&mon[mind].first.first<at[i].first) {
			update(mon[mind].first.second,sz-1,mon[mind].second);
			mind++;
		}
		ret=max(ret,sum(0,sz-1)-at[i].second);
	}
	printf("%lld",ret);
}