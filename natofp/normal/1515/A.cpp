#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

void solve(){
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a(n);
    int s = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s += a[i];
    }
    if(s == x){
        cout << "NO"<<"\n";
        return;
    }
    cout <<"YES"<<"\n";
    int done = 0;
    for(int i=0;i<n;i++){
        if(done + a[i] != x){
            cout << a[i] << " ";
            done += a[i];
            continue;
        }
        else{
            cout << a[i + 1] << " " ;
            cout << a[i] << " " ;
            done += a[i] + a[i + 1];
            i++;
            continue;
        }
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