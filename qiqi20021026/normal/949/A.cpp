#include<bits/stdc++.h>

using namespace std;

#define N 220000

int n,cnt;
char s[N];
set<int> se[2];
vector<int> ans[N];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;++i) se[s[i]-'0'].insert(i);
	while (!se[0].empty()||!se[1].empty()){
		++cnt; int i,lst;
		for (i=0,lst=0;!se[i].empty();i^=1){
			set<int>::iterator it=se[i].upper_bound(lst);
			if (it==se[i].end()) break;
			ans[cnt].push_back(*it);
			lst=*it; se[i].erase(it);
		}
		if (i==0){puts("-1"); return 0;}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;++i){
		printf("%d ",(int)ans[i].size());
		for (int j=0;j<(int)ans[i].size();++j)
			printf(j==(int)ans[i].size()-1?"%d\n":"%d ",ans[i][j]);
	}
	
	return 0;
}