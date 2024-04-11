#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
string s[200005];bool f[200005];pair<int,int> tw[200005];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)f[i]=0;
	map<string,int> m;
	int p[2][2];memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>s[i];
		m[s[i]]=i;
		string ss=s[i];
		for(int j=0;j<ss.size()/2;j++)swap(ss[j],ss[ss.size()-1-j]);
		int t=m[ss];
		if(t){
			f[i]=1;f[t]=1;
		}
		p[s[i][0]-'0'][s[i][s[i].size()-1]-'0']++;
		tw[i].first=s[i][0]-'0';
		tw[i].second=s[i][s[i].size()-1]-'0';
	}
	if(!p[0][1]&&!p[1][0]){
		if(p[0][0]&&p[1][1]){
			puts("-1");return;
		}else{
			puts("0\n");return;
		}
	}
	vector<int> ans;
	ans.clear();
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		if(tw[i].first==0&&tw[i].second==1&&p[0][1]-p[1][0]>1){
			p[1][0]++;
			p[0][1]--;
			ans.push_back(i);
		}
		if(tw[i].first==1&&tw[i].second==0&&p[1][0]-p[0][1]>1){
			p[1][0]--;
			p[0][1]++;
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	return 0;
}