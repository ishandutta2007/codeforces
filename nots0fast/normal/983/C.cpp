#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 1510
#define ch 51
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
int mx = pow(10,4);
int hsh(int mertebe, int bit){
	return bit*10 + mertebe;
}
int dehsh_bit(int a){
	return a/10;
}
int dehsh_mertebe(int a){
	return a%10;
}
void deal(){
	int n;
	cin>>n;
	int dp[mx][10];
	int dp1[mx][10];
	forj(mx)
		fork(10)
			dp[j][k] = inf;
	for(int i=1; i<10; i++)
		dp[0][i] = i-1;
	fori(n){
//		cout<<"we are at "<<i<<"th iteration\n";
		int a, b;
		cin>>a>>b;
		vector<int > qw;
		fori(mx)
			forj(10)
				dp1[i][j] = inf;
		multimap<int,int> dij;
		forj(mx){
			fork(4){
				int z = pow(10,k);
				if((j/z)%10 == 0){
					int yj = j + b*pow(10,k);
					if(dp[j][a] + 1 < dp1[yj][a] ){
						dp1[yj][a] = dp[j][a] + 1;
//						cout<<dp[i+1][yj][a]<<" "<<i+1<<" "<<yj<<" "<<a<<endl;
						dij.insert(mp(dp1[yj][a],hsh(a,yj))); // order dude, mertebe, bit
					}
					break;
				}
			}
		}
		while(dij.size()){
			int wh = (*dij.begin()).ss;
			dij.erase(dij.begin());
			int mertebe = dehsh_mertebe(wh);
			int bit = dehsh_bit(wh);
//			cout<<"the state is mertebe: "<<mertebe<<" bit: "<<bit<<endl;
//			cout<<"dp is "<<dp[dude][bit][mertebe]<<endl;
			int yen = bit;
			int tim = dp1[bit][mertebe];
			forj(4){
				int z = pow(10,j);
				int ql = ( bit/z ) % 10;
				if(ql==mertebe)
					yen-=mertebe*z, ++tim;
			}
			if(yen!=bit){
				if(tim<dp1[yen][mertebe]){
					dp1[yen][mertebe] = tim;
					dij.insert(mp(dp1[yen][mertebe],hsh(mertebe,yen)));
				}
			}
			else{
				if(mertebe!=1){
					if(dp1[yen][mertebe]+1<dp1[yen][mertebe-1]){
						dp1[yen][mertebe-1] = dp1[yen][mertebe]+1;
						dij.insert(mp(dp1[yen][mertebe-1], (hsh(mertebe-1,yen)) )); 
					}
				}
				if(mertebe!=9){
					if(dp1[yen][mertebe]+1<dp1[yen][mertebe+1]){
						dp1[yen][mertebe+1] = dp1[yen][mertebe]+1;
						dij.insert(mp(dp1[yen][mertebe+1],hsh(mertebe+1,yen)));
					}
				}
			}
		}
		fori(mx)
			forj(10)
				dp[i][j] = dp1[i][j];
	}
	int mn = inf;
	fori(10)
		mn = min(mn,dp[0][i]);
	cout<<mn;
}
int main() {
//	while(1)
    deal();
}