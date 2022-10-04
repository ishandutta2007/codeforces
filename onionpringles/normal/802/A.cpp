#include <bits/stdc++.h>
using namespace std;
int a[80];
vector<int> w[81];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	set<int> S;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		w[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		w[i].push_back(100);
		reverse(w[i].begin(),w[i].end());
	}
	int ans=0;
	for(int i=0;i<n;w[a[i]].pop_back(),i++){
		if(S.count(a[i]))continue;
		if((int)S.size() < k){
			ans++;S.insert(a[i]);
		}
		else{
			pair<int,int> hi={-1,-1};
			for(auto &x:S)hi=max(hi,{w[x].back(),x});
			S.erase(hi.second);
			S.insert(a[i]);
			ans++;
		}
	}
	printf("%d\n",ans);
}