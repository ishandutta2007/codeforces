#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
set< pii > s;
vector< pii > v;
vector<int> l[500005];
int last[500005];
int n,sumvis;bool f[500005];
void dfs(int p){
	if(f[p])return ;
	f[p]=1;
	sumvis++;
	for(int i=0;i<l[p].size();i++)dfs(l[p][i]);
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,i));
		v.push_back(make_pair(y,-i));
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=0;i<v.size();i++){
		int a=v[i].first,b=v[i].second;
		if(b>0){
			s.insert(make_pair(a,b));
			last[b]=a;
		}else{
			auto t=s.lower_bound(make_pair(last[-b],-b));
			t++;
			while(t!=s.end()&&sum<n){
				l[-b].push_back((*t).second);
				l[(*t).second].push_back(-b);
				sum++;t++;
			}
			s.erase(make_pair(last[-b],-b));
		}
	}
	if(sum!=n-1){
		cout<<"NO";return 0;
	}
	dfs(1);
	if(sumvis==n)cout<<"YES";else cout<<"NO";
	return 0;
}