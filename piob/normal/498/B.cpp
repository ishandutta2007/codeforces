#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, t, _p, d;
K p;
K dp[5010];
K ft[5010];
K res, stay;

int main(){
	//scanf("%d %d", &n, &t);
	cin >> n >> t;
	dp[0] = 1;
	stay = 1;
	FWD(_i,0,n){
		cin >> p >> d;
		//scanf("%d %d", &_p, &d);
		//p = _p;
		p /= 100;
		K sum = 0;
		K a = 1;
		//printf("przetwarzam %Lf %d, a = %Lf\n", p, d, a);
		FWD(i,0,d){
			res += _i * dp[t-i] * a;
			a *= (1-p);
		}
		a = 1;
		FWD(i,0,d-1) a *= 1-p;
		FWD(i,1,t+1){
			//printf("wyliczam ft[%d]\n", i);
			//printf("mnoze razy %Lf\n", 1-p);
			sum *= (1-p);
			if(i-d >= 0){
				sum -= p * a * dp[i-d];
				//printf("odliczam p * a * (dp[%d] = %Lf + 1) = %Lf\n", i-d, dp[i-d], p * a * (dp[i-d] + 1));
			}
			sum += p * dp[i-1];
			//printf("doliczam p * (dp[%d] = %Lf + 1)\n", i-1, dp[i-1]);
			ft[i] = sum;
			if(i >= d){
				ft[i] +=  a * dp[i-d];
				//printf("i >= d wiec doliczam a * (dp[%d] = %Lf + 1)\n", i-d, dp[i-d]);
			}
			//printf("ft[%d] = %Lf\n", i, ft[i]);
		}
		FWD(i,0,t+1) dp[i] = ft[i];
		//printf("%Lf ze po %d\n", dp[t], _i+1);
		stay -= dp[t];
	}
	FWD(i,0,t+1){
		//printf("%Lf ze wszystko w %d\n", dp[i], i);
		res += dp[i] * n;
	}
	cout.precision(9);
	cout << fixed << res << endl;
	return 0;
}