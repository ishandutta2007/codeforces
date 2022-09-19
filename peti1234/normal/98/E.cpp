#include <bits/stdc++.h>

using namespace std;

const int c=2002;
int n, m, s;
long double dp[c][c], e=1.0;
int main(){
	cin >> n >> m;
	s=n+m;
	for (int i=0; i<=s; i++) {
        dp[i][0]=e;
        dp[0][i]=e/(i+1);
	}
	for (int k=2; k<=s; k++) {
        for (int i=1; i<k; i++) {
            int j=k-i;
            long double a=e, b=1-dp[j][i-1], c=(1-dp[j-1][i])*j/(j+1), d=c+e/(j+1), p=(d-c)/(a-b-c+d);
            dp[i][j]=a*p+c*(1-p);
        }
	}
	cout.precision(20);
	cout << dp[n][m] << " " << 1-dp[n][m] << "\n";
	return 0;
}