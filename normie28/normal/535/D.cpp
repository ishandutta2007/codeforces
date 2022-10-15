#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
#define pb push_back
#define mp make_pair
 
int n, m;
string p;
int a[1000001];
const ll md = 1000000007;
char used[1000001];
 
int prefix_function(const string &s){
    int n = s.length();
    vector<int> pi(n);
    int j = 0;
    for(int i = 1; i < n; i++){
        while(j > 0 && s[j] != s[i]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return j;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> p;
    for(int i = 0; i < m; i++) cin >> a[i];
    int rep = (int)p.length() - prefix_function(p);
    for(int i = 0; i < m - 1; i++){
        if(a[i + 1] - a[i] < p.length() && (a[i + 1] - a[i]) % rep != 0){
            cout << 0 << endl;
            exit(0);
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = a[i] + (int)p.length() - 1; j >= a[i] && !used[j]; j--){
            used[j] = 1;
        }
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            ans *= 26;
            ans %= md;
        }
    }
    cout << ans << endl;
}