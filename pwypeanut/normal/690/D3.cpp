#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define M 1000003ll
ll mem[205];
int n,w,h;
ll pol[110];
int main() {
	scanf("%d%d%d",&n,&w,&h);
	pol[0]=1ll;
	for (int i=1;i<=w+1;i++) {
		pol[i]=(pol[i-1]*(ll)h)%M;
	}
	mem[0]=1ll;
	ll ans=1ll;
	ll cur=1ll;
	for (int i=1;i<=n;i++) {
		mem[i%200]=cur;
		if (i<=w) mem[i%200]=(mem[i%200]+pol[i])%M;
		cur*=(ll)h;
		cur%=M;
		cur+=mem[i%200];
		if (i-w-1>=0) cur-=(pol[w+1]*mem[(i-w-1)%200])%M;
		cur=(cur+M)%M;
	}
	cout<<mem[n%200]<<'\n';
}