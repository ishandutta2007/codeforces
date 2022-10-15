
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define CLEAR(a) memset(a,0,sizeof a)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define fr freopen("input.txt", "r", stdin);
#define fw freopen("output.txt", "w", stdout);
#define int long long
typedef long long LL;
typedef pair<int,int> pii;
 
int MOD ;
const int MAX = 1e5 + 5;
 
 
#define Mat vector< vector < int > >
 
 
void Resize_Mat(int n , int m, Mat &M){
    M.clear();
    for(int j = 0;j < n;j++) {
        M.push_back( vector< int >() );
        M[j].clear();
        M[j].resize(m);
        for(int i = 0;i < m;i++) M[j][i] = 0;
    }
}
 
Mat Mat_Mul(Mat A , Mat B){
    Mat Ans; 
    int n , m;
    Resize_Mat(n = A.size() , m = A[0].size() , Ans);
    for(int j = 0;j < n;j++){
        for(int i = 0;i < m;i++){
            Ans[j][i] = 0;
            for(int k = 0;k < m;k++){
                Ans[j][i] += A[j][k]*B[k][i];
                Ans[j][i] %= MOD;
            }
        }
    }
    return Ans;
}
 
 
Mat Mat_Expo(Mat M , int power){
    if(power == 1) return M;
    Mat res = Mat_Expo(M , power/2);
    res = Mat_Mul(res , res);
    if(power%2) res = Mat_Mul(res , M);
    return res;
}
 
int mod_pow(int base, int e){
	int ret = 1%MOD;
	while(e){
		if(e%2) ret = (ret*base)%MOD;
		base = (base*base)%MOD;
		e /= 2;
	}
	return ret;
}
 
 main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    int n,k,l;
    cin >> n >> k >> l >> MOD;
     if(l < 63 &&  (1LL << l) <= k){
        cout << 0;
        return 0;
    }
 
    int ret = 1%MOD;
    Mat mat;
    Resize_Mat(2,2,mat);
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    mat = Mat_Expo(mat, n);
    int f1, f2;
    f1 = (mat[0][0] + mat[0][1])%MOD;
    f2 = mod_pow(2,n);
    for(int i=0;i<l;i++){
    	if(k&(1LL<<i)) ret = (ret*((f2-f1+MOD)%MOD))%MOD;
        else ret = (ret*f1)%MOD;
    }
    cout << ret;
    return 0;
}