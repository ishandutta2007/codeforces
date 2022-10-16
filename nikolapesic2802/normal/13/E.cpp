#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dec(x, y) fixed << setprecision((y)) << (x)
#define xx first
#define yy second
#define srt(v) sort((v).begin(), (v).end())
#define srtr(v) sort((v).rbegin(), (v).rend())
#define pb push_back
#define popb pop_back
#define sz(a) (int)(a).size()
#define len(a) (int)(a).length()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, a[100099], iskok[100099], gde[100099], posl[100099], blok[100099], duz;
int main() {
    ios;
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(duz=1; duz*duz<=n; ++duz);
    for(int i=1, j=1, p=1; i<=n; ++i, ++j) {
        if(j==duz+1) {++p; j=1;}
        blok[i]=p;
    }
    for(int i=n; i>=1; --i) {
        if(i+a[i]>n || blok[i]!=blok[i+a[i]]) {iskok[i]=1; gde[i]=i+a[i]; posl[i]=i;}
        else {iskok[i]=iskok[i+a[i]]+1; gde[i]=gde[i+a[i]]; posl[i]=posl[i+a[i]];}
    }
    while(m--) {
        int t, b;
        cin >> t >> b;
        if(t==0) {
            int c; cin >> c;
            a[b]=c;
            if(b+c>n || blok[b]!=blok[b+c]) {iskok[b]=1; gde[b]=b+c; posl[b]=b;}
            else {iskok[b]=iskok[b+c]+1; gde[b]=gde[b+c]; posl[b]=posl[b+c];}
            for(int i=b-1; blok[i]==blok[b]; --i) {
            	if(i+a[i]>n || blok[i]!=blok[i+a[i]]) {iskok[i]=1; gde[i]=i+a[i]; posl[i]=i;}
        			else {iskok[i]=iskok[i+a[i]]+1; gde[i]=gde[i+a[i]]; posl[i]=posl[i+a[i]];}
            }
        }
        else {
            int rez=0;
            int zap;
            for(int i=b; i<=n; i=gde[i]) {rez+=iskok[i]; zap=posl[i];}
            cout << zap << ' ' << rez << "\n";
        }
    }
    return 0;
}