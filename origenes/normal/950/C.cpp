#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=213456;
char s[maxn];
int PREV[maxn], NEXT[maxn];
vector<int> ans[maxn];
queue<int> q;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	scanf("%s", s+1);
	int n=strlen(s+1), cnt=0;
	for(int i=1; i<=n; i++){
		if(s[i]=='0') cnt++;
		else cnt--;
		if(cnt<0){
			puts("-1");
			return 0;
		}
	}
	cnt=0;
	for(int i=n; i>=1; i--){
		if(s[i]=='0') cnt++;
		else cnt--;
		if(cnt<0){
			puts("-1");
			return 0;
		}
	}
//	queue<int> q;
	for(int i=1; i<=n; i++){
		if(s[i]=='0') q.push(i);
		else{
			int u=q.front(); q.pop();
			PREV[i]=u; NEXT[u]=i;
		}
	}
	while(!q.empty()){
//		queue<int> tmp;
//		swap(q, tmp);
		q.pop();
	}
	for(int i=n; i>=1; i--){
		if(s[i]=='0') q.push(i);
		else{
			int u=q.front(); q.pop();
			PREV[u]=i; NEXT[i]=u;
		}
	}
	int tot=0;
	for(int i=1; i<=n; i++){
		if(PREV[i]) continue;
		for(int u=i; u; u=NEXT[u])
			ans[tot].push_back(u);
		tot++;
	}
	cout<<tot<<endl;
	for(int i=0; i<tot; i++){
		cout<<ans[i].size();
		for(int it:ans[i])
			cout<<' '<<it;
		cout<<endl;
	}
	return 0;
}