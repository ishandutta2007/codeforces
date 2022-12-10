#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
	ios_base::sync_with_stdio(false);
    int m, n;
    cin>>m>>n;
    bool a1[m], a2[n], b[m+1][n+1];
    rep(i, m)
        rep(j, n)
            cin >> b[i][j];
    memset(a1, true, sizeof a1);
    memset(a2, true, sizeof a2);
    rep(i, m){
        rep(j, n){
            if(!b[i][j]){
                a2[j] = false;
                a1[i]=false;
			}
        }
    }
	bool a[m][n];
    rep(i, m)
        rep(j, n)
            a[i][j] = a1[i] and a2[j];
	rep(i, m){
		rep(j, n){
			bool tmp = false;
			rep(ii, m)
				tmp = tmp or a[ii][j];
			rep(jj, n)
				tmp = tmp or a[i][jj];
			if(tmp != b[i][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
    rep(i, m){
        rep(j, n-1)
            cout<< (a1[i] and a2[j]) <<' ';
        cout << (a1[i] and a2[n-1]) << endl;
    }
	return 0;
}