#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)t; (i)++)
#define reu(i, s, e) for(ll (i) = (ll)s; (i) <= (ll)e; (i)++)
#define rer(i, s, e) for(ll (i) = (ll)s; (i) < (ll)e; (i)++)
#define mset(arr, val) memset(arr, val, sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int a[26];
    mset(a, 0);
    rep(i, s.size())
        a[s[i]-'a']++;
    for(int i = 25; i >= 0; i--){
        if(a[i] > 0){
            rep(j, a[i])
                cout << char(i + 'a');
            return 0;
        }
    }
	return 0;
}