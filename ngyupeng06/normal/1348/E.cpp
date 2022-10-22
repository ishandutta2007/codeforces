#include <bits/stdc++.h>
 
using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back
 
long long n, k, a[505], b[505], ans, suma = 0, sumb = 0;
bool sa[505][505], sb[505][505];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> a[i] >> b[i];
		suma += a[i], sumb += b[i];
	}
	ans = suma / k + sumb / k;
	long long bruh = 0;
	long long x = suma % k;
	long long y = sumb % k;
	sa[0][0] = sb[0][0] = true;
	if (x+y>=k){
		for (int i=0; i<n; i++){
			for (int j=0; j<k; j++){
				sa[i+1][j] = sa[i][j];
				sb[i+1][j] = sb[i][j];
			}
			for (int j=0; j<=min(a[i],k-1); j++){
				if (k - j <= b[i]){
					for (int l=0; l<k; l++){
						if (sa[i][l]) sa[i+1][(l+j)%k] = true;
					}
				}
			}
		}
		for (int i=0; i<k; i++){
			if (sa[n][i]){
				if ((x + k - i)%k + (y + i)%k < k) bruh = 1;
			}
		}
	}
		
	cout << ans + bruh;
}