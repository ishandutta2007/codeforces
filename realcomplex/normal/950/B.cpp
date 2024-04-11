#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	int n,m;
	while(cin >> n >> m){
		int a[n],b[m];
		for(int i = 0 ;i<n;i++)
			cin >> a[i];
		for(int j = 0;j<m;j++)
			cin >> b[j];
		int p = 0;
		int s1 = 0,s2 = 0;
		int ans = 0;
		for(int i = 0;i<n;i++){
			s1 += a[i];
			while(s2 < s1)
				s2 += b[p++];
			if(s1 == s2)
				ans ++ ;
		}
		cout << ans << "\n";
	}
	return 0;
}