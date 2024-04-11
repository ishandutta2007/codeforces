#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m;
char buf[4100];
int enu[16384];
int ans;

int col[16384];
int newc[16384];
int par[8200];
int par_temp[8200];
int mark[8200];

int R(int x){ return (x==par[x])?x:(par[x]=R(par[x])); }
int Join(int a, int b){ a=R(a); b=R(b); if(a==b) return 0; par[a]=b; return 1; }

int main()
{
	read(n, m);
	for(int j=0; j<8200; ++j) par_temp[j] = j;
	for(int i = 1; i <= n; ++i){
		scanf("%s", buf);
		
		int p=0;
		for(int j=0; j<(m>>2); ++j){
			int val=((buf[j] >= 65) ? (buf[j]-65 + 10) : (buf[j]-48));
			for(int b=3; b>=0; --b) enu[p++] = (1&(val >> b));
		}
		
		memcpy(par, par_temp, sizeof(par));
		fill(mark, mark+8200, 0);
		
		for(int j=0; j<m;){
			if(!enu[j]){ newc[j]=0; ++j; continue; }
			int k;
			int my_c = -1;
			for(k=j; k<m && enu[k]; ++k){
				if(col[k]){
					if(my_c == -1) my_c = col[k];
					else ans -= Join(my_c, col[k]);
				}
			}
			if(my_c == -1){
				++ans;
			}
			for(int l=j; l<k; ++l) newc[l]=my_c;
			j=k;
		}
		
		int nci=0;
		for(int j=0; j<m; ++j){
			if(!enu[j]){ col[j]=0; continue; }
			if(newc[j] < 0){
				++nci;
				while(j<m && newc[j]<0){
					col[j]=nci; ++j;
				}
				--j; continue;
			}
			int r = R(newc[j]);
			if(!mark[r]){
				mark[r] = ++nci;
			}
			col[j] = mark[r];
		}
	}
	
	printf("%d\n", ans);
	return 0;
}