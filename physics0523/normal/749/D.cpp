#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi=pair<int,int>;
using ppi=pair<pi,pi>;
using Graph=vector<vector<int>>;
using Stg=vector<set<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pi> in(n);
	vector<int> mem(n+1,0);
	vector<int> minin(n+1,inf);
	Stg info(n+1);
	for(int i=0;i<n;i++){
		cin >> in[i].first >> in[i].second;
		mem[in[i].first]++;
		minin[in[i].first]=min(minin[in[i].first],in[i].second);
		info[in[i].first].insert(in[i].second);
	}
	int q;
	cin >> q;
	vector<ppi> qv(q);
	Graph g(q);

	for(int i=0;i<q;i++){
		int k;
		cin >> k;
		for(int j=0;j<k;j++){
			int v;
			cin >> v;
			g[i].push_back(v);
		}
		qv[i]={{(n-1)/2,i},{0,n-1}};
	}

	int th=0;
	unordered_set<int> st;
	for(int i=1;i<=n;i++){
		if(mem[i]>0){
			th++;
			st.insert(i);
		}
	}

	vector<int> rss(q,-1);
	vector<int> price(q,-1);
	Stg cinfo=info;
	for(int rp=0;rp<=20;rp++){
		sort(qv.begin(),qv.end());
		vector<int> a=mem;
		unordered_set<int> nst=st;
		int tg=0;
		int ch=th;
		for(int i=0;i<n;i++){
			while(tg<q && qv[tg].first.first<i){tg++;}
			while(tg<q && qv[tg].first.first==i){
				int qid=qv[tg].first.second;
				if(qv[tg].second.first>qv[tg].second.second){
					qv[tg].first.first=qv[tg].second.first;
					if(rp==20){
						//cerr << rp << ' ' << qid << '\n';
						for(auto &nx : g[qid]){if(a[nx]>0){nst.erase(nx);}}
						if(nst.empty()){
							rss[qid]=0;
							price[qid]=0;
						}
						else{
							rss[qid]=(*nst.begin());
							price[qid]=(*cinfo[rss[qid]].begin());
						}
						for(auto &nx : g[qid]){if(a[nx]>0){nst.insert(nx);}}
					}
					tg++;continue;
				}
				int cnt=ch;
				for(auto &nx : g[qid]){if(a[nx]>0){cnt--;}}
				if(cnt<=1){qv[tg].second.second=i-1;}
				else{qv[tg].second.first=i+1;}
				qv[tg].first.first=(qv[tg].second.first+qv[tg].second.second)/2;
				tg++;
			}
			a[in[i].first]--;
			if(a[in[i].first]==0){
				nst.erase(in[i].first);
				ch--;
			}
			if(rp==20){cinfo[in[i].first].erase(in[i].second);}
		}
	}

	for(int i=0;i<q;i++){
		cout << rss[i] << ' ' << price[i] << '\n';
	}
  return 0;
}