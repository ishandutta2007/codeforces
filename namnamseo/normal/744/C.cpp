#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define pb push_back
#define all(x) (x).begin(),(x).end()

int ax[20], ay[20];
int cx[20], cy[20];

typedef pair<int,int> pp;

vector<pp> dps[1<<16];

const int inf=2e9;

int main()
{
    int n;
    read(n);
    for(int i=0; i<n; ++i){
		char a[5];
		int b, c;
		scanf("%s%d%d", a, &b, &c);
		ax[i]=b; ay[i]=c;
		if(a[0]=='R') cx[i]=1; else cy[i]=1;
    }
    dps[0].pb(pp{0, 0});
    for(int i=1; i<(1<<n); ++i){
		unordered_map<int,int> m;
		int dx=0, dy=0;
		for(int j=0; j<n; ++j) if(1&(i>>j)) dx+=cx[j], dy+=cy[j];
		for(int j=0; j<n; ++j) if(1&(i>>j)){
			dx-=cx[j]; dy-=cy[j];
			for(auto tmp:dps[i^(1<<j)]){
				int val=tmp.second, pt=tmp.first;
				int x=max(0, -pt), y=max(0, pt);
				int tx=max(0, ax[j]-dx), ty=max(0, ay[j]-dy);
				int dv = max({tx-x, ty-y, 0});
				int nv=val+dv;
				int nx=x+dv-tx, ny=y+dv-ty;
				ny -= nx;
				if(m.find(ny) == m.end()) m[ny]=inf;
				m[ny]=min(m[ny], nv);
			}
			dx+=cx[j]; dy+=cy[j];
		}
		for(auto tmp:m) dps[i].pb(tmp);
    }
    int ans=inf;
    for(auto tmp:dps[(1<<n)-1]) ans=min(ans, tmp.second);
    printf("%d\n", ans+n);
    return 0;
}