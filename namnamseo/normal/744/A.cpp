#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
typedef pair<int,int> pp;
#define pb push_back

int n, m, k;

vector<int>gov;

int par[1010];
int size[1010];
bool igov[1010];
int ec[1010];
int root(int x){ return (x==par[x])?x:(par[x]=root(par[x])); }
void join(int a, int b){
	a=root(a); b=root(b);
	par[a]=b;
	if(a!=b) size[b]+=size[a];
}

vector<pp> e;

int main()
{
    read(n, m, k);
    for(int i=1; i<=n; ++i) par[i]=i, size[i]=1;
    gov.resize(k); for(int& x:gov) read(x);
    for(int i=0; i<m; ++i){
		int a, b; read(a, b);
		join(a, b);
		e.pb(pp{a, b});
    }
    for(int x:gov) igov[root(x)]=1;
    for(auto tmp:e){
		++ec[root(tmp.first)];
    }
    int ans=0;
    int ms=0, ngv=0;
    for(int i=1; i<=n; ++i) if(root(i)==i){
		if(igov[i]){
			ans += size[i]*(size[i]-1)/2 - ec[i];
			ms=max(ms, size[i]);
		} else {
			ans -= ec[i];
			ngv += size[i];
		}
    }
    ans += ms*ngv + ngv*(ngv-1)/2;
    printf("%d\n", ans);
    return 0;
}