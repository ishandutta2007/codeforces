#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
using namespace std;
const int c=26;
int n, m, fa[c], t[c][c], ans;
string x, y;
int getfa(int x){
    if (fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> x >> y;
	n=x.size(), m=y.size();
	for (int i=m; i<=n; i++) {
		memset(t,0,sizeof(t));
		for (int j=1; j<=m; j++) t[x[i-m+j-1]-'a'][y[j-1]-'a']=1;
		for (int j=0; j<c; j++) fa[j]=j; ans=0;
		for (int x=0; x<c; x++) for (int y=0; y<c; y++) if (t[x][y]) {
			int fx=getfa(x),fy=getfa(y);
			if (fx!=fy) fa[fx]=fy,ans++;
		}
		cout << ans << " ";
	}
	return 0;
}