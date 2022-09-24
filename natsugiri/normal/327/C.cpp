#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD= 1000000007;
typedef long long LL;
typedef vector<LL> Ary;
typedef vector<Ary> Mat;

Mat Id(int n) {
    Mat r(n, Ary(n, 0));
    for (int i=0; i<n; i++) r[i][i]=1;
    return r;
}
Mat mulMatMod(const Mat&a, const Mat&b, LL mod) {
    int m=a.size(), n=a[0].size(), p=b[0].size();
    Mat r(m, Ary(p, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<p; k++) {
                r[i][k]=(r[i][k]+a[i][j]*b[j][k])%mod;
            }
        }
    }
    return r;
}

Mat powMatMod(const Mat&a, LL b, const LL&mod) {
    if (b==1) return a;
    if (b%2) return mulMatMod(a, powMatMod(a, b-1, mod), mod);
    return powMatMod(mulMatMod(a, a, mod), b/2, mod);
}

string S;
int K, L;
LL dp[100010][4];

vector<LL> calc(vector<int>v) {
    memset(dp, 0, sizeof dp);
    for (int j=0; j<3; j++) {
	dp[0][j] = v[j];
	dp[0][3] += v[j];
    }
    for (int i=0; i<L; i++) {
	for (int j=0; j<3; j++) dp[i+1][j] = dp[i][j];

	if (S[i]=='0') dp[i+1][0] += dp[i][3] + 1;
	else if (S[i]=='5') dp[i+1][2] += dp[i][3] + 1;
	else dp[i+1][1] += dp[i][3] + 1;

	for (int j=0; j<4; j++) {
	    while (dp[i+1][j]>=MOD) dp[i+1][j] -= MOD;
	    if (j==3) break;
	    dp[i+1][3] += dp[i+1][j];
	}
    }
    LL a[3] = {dp[L][0], dp[L][1], dp[L][2]};
    return vector<LL>(a, a+3);
}
int main() {
    cin>>S>>K;
    L=S.size();

    Mat A(4, Ary(4,0));
    int z[3]={};
    vector<LL>r;

    r = calc(vector<int>(z, z+3));
    for (int j=0; j<3; j++) A[j][3]=r[j];
    A[3][3]=1;

    z[0] = 1;
    r = calc(vector<int>(z, z+3));
    for (int j=0; j<3; j++) A[j][0] = (r[j]-A[j][3]+MOD)%MOD;

    z[0] = 0; z[1] = 1;
    r = calc(vector<int>(z, z+3));
    for (int j=0; j<3; j++) A[j][1] = (r[j]-A[j][3]+MOD)%MOD;

    z[1] = 0; z[2] = 1; 
    r = calc(vector<int>(z, z+3));
    for (int j=0; j<3; j++) A[j][2] = (r[j]-A[j][3]+MOD)%MOD;

    A = powMatMod(A, K, MOD);
    LL ans = A[0][3] + A[2][3];
    cout<<ans%MOD<<endl;
	
    return 0;
}