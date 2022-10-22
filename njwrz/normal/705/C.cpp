#include <bits/stdc++.h> 
using namespace std;
bool vis[300005];
vector<int> v;
int a[300005],b[300005],c[300005];
int main(){
	int n,m;
	cin>>n>>m;
	int d=0,x,y;
	int ss=0;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		if(x==1){
			v.push_back(y);
			a[y]++;
		}
		if(x==2){
			d+=a[y]-b[y];
			b[y]=a[y];
		}
		if(x==3) {
			for(int j=ss;j<y;j++){
				if(c[v[j]]<b[v[j]])c[v[j]]++;
				else c[v[j]]++,b[v[j]]++,d++;
			}
			ss=max(ss, y);
		}
		cout<<v.size()-d<<'\n';
	}
	return 0;
}