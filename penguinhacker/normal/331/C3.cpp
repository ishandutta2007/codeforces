#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll brute(ll n) {
    ll count = 0;
    while (n>0) {
        int best=0;
        ll s=n;
        while (s>0) {
            best = max(best, (int)(s%10));
            s /= 10;
        }
        n -= best;
        count++;
    }
    return count;
}

ll n, ans, dp[18][10][10]; // digit, last digit, maximum digit before
int nxt[18][10][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<10; ++i) {
		dp[0][i][0]=i>0;
		for (int j=1; j<10; ++j) {
			if (j<=i) {
				dp[0][i][j]=2;
				nxt[0][i][j]=10-j;
			} else {
				dp[0][i][j]=1;
				nxt[0][i][j]=10+i-j;
			}
		}
	}
	for (int i=1; i<18; ++i) {
		for (int j=0; j<10; ++j) {
			for (int k=0; k<10; ++k) {
				int cj=j;
				for (int l=9; ~l; --l) {
					dp[i][j][k]+=dp[i-1][cj][max(k, l)];
					cj=nxt[i-1][cj][max(k, l)];
				}
				nxt[i][j][k]=cj;
			}
		}
	}
	//cout << dp[1][0][0] << " " << brute(90) << endl;
	cin >> n;
	//cout << "INTENDED : " << brute(n) << endl;
	while(n>=10) {
		vector<int> d(19);
		for (ll i=0; n; ++i, n/=10)
			d[i]=n%10;
		int ind=0;
		while(d[ind+1]==9)
			++ind;
		int mx=*max_element(d.begin()+ind+1, d.end());
		//cout << ind << " " << d[0] << " " << mx << endl;
		if (mx==0) {
			ans+=dp[ind][d[0]][mx];
			break;
		}
		ans+=dp[ind][d[0]][mx];
		d[0]=nxt[ind][d[0]][mx];
		for (int i=1; i<=ind; ++i)
			d[i]=9;
		for (int i=ind+1; i<19; ++i) {
			if (d[i]>0) {
				--d[i];
				break;
			}
			d[i]=9;
		}
		for (int i=18; ~i; --i)
			n=10*n+d[i];
		//cout << n << endl;
	}
	cout << ans+(n>0);
	return 0;
}