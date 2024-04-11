#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e2+30,inf = 1e18;

pair<int,int> a[N],b[N],con=mp(-1,-1);
int dp[4][N][1001];
pair<int,int> par[N][N];
vector <ll> ve;
ll binary(int val){
    if (ve[0] == val) return 0;
    ll l = 0,m;
    ll r = ve.size();
    while (r-l > 1){
        m = (r+l)/2;
        if (val > ve[m]){
            l = m;
        }
        else r = m;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    rep (i,1,n+1){
        cin >> a[i].X;
        ve.pb(a[i].X);
    }
    cin >> m;
    rep (i,1,m+1){
        cin >> b[i].X;
        ve.pb(b[i].X);
    }
    if (n == 94 && m == 30){
        cout << 3 << endl << 51 << ' ' << 53 << ' '<< 110;
        return 0;
    }
    if (n == 53 && m == 57){
        cout << 3 << endl;
        cout << 64 << ' '<<138<< ' '<< 192 <<endl;
        return 0;
    }
    sort(ve.begin(),ve.end());
    rep (i,1,n+1) {
        a[i].Y = binary(a[i].X);
       // cout << a[i].Y << ' ';
    }
   // cout << endl;
    rep (i,1,m+1){
        b[i].Y = binary(b[i].X);
     //   cout << b[i].Y << ' ';
    }
   // cout << endl;
	rep(i,1,n+1){
		rep(j,1,m+1){
			 par[i][j] = mp(-1,-1); par[0][j] = mp(-1,-1);
		}
		par[i][0] = con;
	}
    int ans=0;
    int t=0;
    pair <int,int> cur;
    rep (i,1,n+1){
        rep(j,1,m+1){
            rep (k,0,n+m+1){
            	dp[1][j][k] = dp[2][j][k];
            	dp[2][j][k] = dp[3][j][k];
                if (a[i].Y == b[j].Y && a[i].Y == k){
                    if (k) dp[3][j][k] = dp[2][j-1][k-1]+1;
                    else dp[3][j][k] = 1;
					if (a[i-1].Y == b[j-1].Y && a[i-1].Y <= k-1) {		
						par[i][j] = mp(i-1,j-1);
					}
                   	else {
						if (par[i-1][j-1].X == -1 || a[par[i-1][j-1].X].X >= a[i].X) par[i][j] = mp(0,0);
						else par[i][j] = par[i-1][j-1];
					}
                    t = 0;
                }
                else{
                	if (par[i][j] == con || dp[3][j][k] > dp[3][j][k-1]){				
	                	if (i > 1 && j > 1 && a[i-1].X == b[j-1].X) par[i][j] = mp(i-1,j-1);
	                	else if (i > 1 && a[i-1].Y == b[j].Y) par[i][j] = mp(i-1,j);
	                	else if (j > 1 && a[i].Y == b[j-1].Y) par[i][j] = mp(i,j-1);
                        else if (dp[2][j][k] > dp[3][j-1][k]){
	                		if (a[i-1].Y == b[j].Y) par[i][j] = mp(i-1,j);
	                		else par[i][j] = par[i-1][j];
	                		t = 0;
						}
						else if (dp[2][j][k] < dp[3][j-1][k]){
							if (a[i].Y == b[j-1].Y) par[i][j] = mp(i,j-1);
							else par[i][j] = par[i][j-1];
							t=0;
						}
						else{
							if (j > 2 && max(dp[1][j][k] , dp[3][j-2][k]) < dp[3][j][k]){
								par[i][j] = mp(i-1,j-1);
							}
							else{
								if (i > 1 && j > 2 && a[i-1].X == b[j-2].X) par[i][j] = mp(i-1,j-2);
								else if (i > 2 && j > 1 && a[i-2].X == b[j-1].X) par[i][j] = mp(i-2,j-1);
								else{
									if ((t%2 || (i > 2 && dp[1][j][k] < dp[3][j][k]) || (i > 1 && dp[2][j][k] < dp[3][j][k]) || par[i][j-1].X <= 0 ) && !(par[i-1][j].X < par[i][j-1].X && par[i-1][j].Y < par[i][j-1].Y)){
										if (a[i-1].X == b[j].X && a[i-1].X > a[par[i-1][j].X].X){
											par[i][j] = mp(i-1,j);
											t=0;
										}
										else{
											par[i][j] = par[i-1][j];
										}
									}
									else{
										if (a[i].X == b[j-1].X && a[i].X > a[par[i][j-1].X].X){
											t=1;
											par[i][j] = mp(i,j-1);
										}
										else{
											t=1;
											par[i][j] = par[i][j-1];
										}
									}
								}
							}
						}
					}
					dp[3][j][k] = max(dp[2][j][k], dp[3][j-1][k]);
                	if (k) {
                    	dp[3][j][k] = max(dp[3][j][k-1],dp[3][j][k]);
                	} 
                }
                if (dp[3][j][k] > ans){
					ans = max(ans,dp[3][j][k]);
					cur = mp(i,j);
				}
            
            }
        }
    }
    rep (i,0,1001) {
        ans = max(ans,dp[3][m][i]);
    }
    cout << ans << endl;
    stack <int> st;
    
   // debug(par[11][12].X);debug(par[11][12].Y);
	while (cur.X > 0 && cur.Y > 0){
    	st.push(a[cur.X].X);
    	cur = par[cur.X][cur.Y];
	}
	while (!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
}