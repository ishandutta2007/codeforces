#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#define MN 1500
typedef std::pair<int,int> pii;

int n,m,b[MN+5][MN+5],c[MN+5][MN+5],d[MN+5][MN+5];
std::map<std::vector<int>,std::vector<int>> mp;

bool check(std::set<pii>& segs,int x){
	for(pii s:segs)
		if(c[s.first][x]<s.second) return false;
	std::set<pii> toErase,toInsert;
	for(pii s:segs){
		if(d[s.first][x]<s.second){
			toErase.insert(s);
			int p = s.first;
			while(d[p][x]<s.second){
				toInsert.insert(pii(p,d[p][x]));
				p = d[p][x]+1;
			}
			toInsert.insert(pii(p,s.second));
		}
	}
	for(pii s:toErase)
		segs.erase(s);
	for(pii s:toInsert){
		if(s.first==s.second)
			continue;
		segs.insert(s);
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		std::vector<int> a;
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
		mp[a].push_back(i);
	}
	for(auto& p:mp)
		std::reverse(p.second.begin(),p.second.end());
	for(int i=1;i<=n;i++){
		std::vector<int> a;
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
			b[i][j] = x;
		}
		if(mp.find(a)==mp.end()||mp[a].size()==0){
			puts("-1");
			return 0;
		}
		b[i][m+1] = mp[a].back();
		mp[a].pop_back();
	}
	for(int j=1;j<=m+1;j++){
		for(int i=n,tc=n,td=n;i>=1;i--){
			if(b[i][j]>b[i+1][j]) tc = i;
			if(b[i][j]!=b[i+1][j]) td = i;
			c[i][j] = tc;
			d[i][j] = td;
		}
	}
	std::set<pii> segs;
	segs.insert(pii(1,n));
	std::set<int> r;
	for(int i=1;i<=m+1;i++)
		r.insert(i);
	std::vector<int> ans;
	while((int)ans.size()!=m+1){
		bool flag = false;
		for(int x:r){
			if(check(segs,x)){
				r.erase(x);
				ans.push_back(x);
				flag = true;
				break;
			}
		}
		if(!flag){
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",(int)ans.size()-1);
	std::reverse(ans.begin(),ans.end());
	for(int x:ans)
		if(x!=m+1) printf("%d ",x);
	puts("");
}