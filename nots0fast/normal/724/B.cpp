#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,2) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

int arr[MAX][MAX];


bool check(int n, int m, int c1, int c2){
	bool ans = 1;
	fori(n){
		bool row_ = 0;
		forj(m){
			fork(m){
				swap(arr[i][j], arr[i][k]);
				bool gg = 1;
				forl(m){
					if(l==c1 || l==c2){
						if(arr[i][l] == l+1)
							gg = 0;
					}
					else{
						if(arr[i][l] != l+1)
							gg = 0;
					}
				}
				swap(arr[i][j], arr[i][k]);
				row_ |= gg;
			}
		}
		//cout<<"at choosing "<<c1<<" "<<c2<<" row number "<<i<<" is "<<row_<<endl;
		ans&=row_;
	}
	return ans;
}


void deal(){
	int n,m;
	cin>>n>>m;
	fori(n)
		forj(m)
			cin>>arr[i][j];
	bool ans = check(n,m,-1,-1);
	fori(m)
		forj(m){
			if(i==j)
				continue;
			ans|=check(n,m,i,j);
		}
	(ans ) ? (cout<<"YES") : (cout<<"NO");
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1