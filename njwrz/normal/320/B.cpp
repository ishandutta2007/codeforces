#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define add(a,b) v[a].pb(b)
using namespace std;
vector <int> v[105];
pair<int,int> a[105];
int t[105],cnt,mb,ans;
bool in(int x,int y){
	return (a[x].f<a[y].f&&a[y].f<a[x].s)||
	(a[x].f<a[y].s&&a[y].s<a[x].s);
}
void dfs(int p){
	if(t[p])return ;
	t[p]=1;
	if(p==mb){ans=1;return;}
	for(int i=0;i<v[p].size();i++)dfs(v[p][i]);
}
int main(){
	int n;
	cin>>n;
	int x,y,z;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		if(x==1){
			cnt++;
			a[cnt].f=y;
			a[cnt].s=z;
			for(int j=1;j<cnt;j++){
				if(in(j,cnt)){
					add(cnt,j);
				}
				if(in(cnt,j)){
					add(j,cnt);
				}
			}
		}else{
			ans=0;mb=z;
			memset(t,0,sizeof(t));
			dfs(y);
			if(ans){
				puts("YES");
			}else puts("NO");
		}
	}
	return 0;
}