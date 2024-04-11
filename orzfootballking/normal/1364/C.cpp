#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,a[100005],b[100005];
bool f[1100005],p[1100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],f[a[i]]=1;
	int last=-1,ans=0;
	FOR(i,1,n){
		if(a[i]!=a[i-1]){
			p[a[i-1]]=1;
			while(p[ans])ans++;
			if(ans!=a[i]){
				cout<<-1;RE 0;
			}
			b[i]=a[i-1];
		}else{
			last++;
			while(f[last]||p[last])last++;
			b[i]=last;p[last]=1;
		}
		while(p[ans])ans++;
	}
	FOR(i,1,n)cout<<b[i]<<' ';
	RE 0;
}