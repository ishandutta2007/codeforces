#include <bits/stdc++.h>
using namespace std;
int a[500000];
vector<int> w[500000];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	set<pair<int,int> > S;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		w[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		w[i].push_back(2012345678);
		reverse(w[i].begin(),w[i].end());
	}
	int ans=0;
	for(int i=0;i<n;i++){
		auto it = S.find({i,a[i]});
		w[a[i]].pop_back();
		if(it!=S.end()){
			S.erase(it);
		}
		else if((int)S.size() < k){
			ans++;
		}
		else{
			auto it = --S.end();
			S.erase(it);
			ans++;
		}
		S.insert({w[a[i]].back(),a[i]});
	}
	printf("%d\n",ans);
}