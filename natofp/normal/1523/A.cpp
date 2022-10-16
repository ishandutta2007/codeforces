#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 1005;
int a[nax];
int b[nax];

int n,m;

void sim(){
    for(int i=1;i<=n;i++) b[i] = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 1) b[i] = 1;
        else{
            int cnt = 0;
            if(i > 1 && a[i - 1] == 1) cnt++;
            if(i < n && a[i + 1] == 1) cnt++;
            if(cnt == 1) b[i] = 1;
        }
    }
    for(int i=1;i<=n;i++) a[i] = b[i];
}

void solve(){
    cin >> n >> m;
    string s; cin >> s;
    for(int i=0;i<n;i++){
        a[i + 1] = s[i] - '0';
    }

    for(int i=0;i<min(1111,m);i++){
        sim();
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}