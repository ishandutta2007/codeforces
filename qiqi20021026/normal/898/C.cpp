#include<bits/stdc++.h>

using namespace std;

int n,m,cnt;
map<string,int> mp;
string s,ss,st[300],out[300];
vector<string> vec[300];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>s>>m;
		if (!mp.count(s)) mp[s]=++cnt,st[cnt]=s;
		int c=mp[s];
		for (int j=1;j<=m;j++){
			cin>>ss; reverse(ss.begin(),ss.end());
			vec[c].push_back(ss);
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++){
		sort(vec[i].begin(),vec[i].end());
		int xb=0;
		for (int j=0;j<vec[i].size()-1;j++){
			bool fl=0;
			s=vec[i][j]; ss=vec[i][j+1];
			for (int k=0;k<s.length();k++)
				if (s[k]!=ss[k]){fl=1; break;}
			if (fl) out[++xb]=s;
		}
		out[++xb]=vec[i][vec[i].size()-1];
		cout<<st[i]<<' '<<xb;
		for (int j=1;j<=xb;j++){reverse(out[j].begin(),out[j].end()); cout<<' '<<out[j];}
		puts("");
	}
	
	return 0;
}