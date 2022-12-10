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
typedef pair<int, int> pie;

int a[200];
int t[200];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	FOR(i, 1, n)
        cin >> a[i];
    int max_ = 0;
    for(int i = n; i > 0; i--)
        t[i] = t[i + 1] + a[i];
    int p = 0;
    FOR(i, 1, n){
        int s = 0;
        FOR(j, i, n){
            if(a[j] == 0)
                s++;
            if(s + p + t[j + 1] > max_)
                max_ = s + p + t[j + 1];
        }
        p += a[i];
    }
    cout << max_ << endl;
	return 0;
}