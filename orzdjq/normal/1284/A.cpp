#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=25;
int n,m;
string a[Maxn],b[Maxn];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<m;i++) cin>>b[i];
	int q;
	cin>>q;
	while (q--){
		int x;
		cin>>x;
		x--;
		cout<<a[x%n]<<b[x%m]<<endl;
	}
}