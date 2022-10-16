#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 2e5 + 5;
char s[nax];

bool ok(string z){
    int bal = 0;
    for(char x : z){
        if(x == '(') bal++;
        else bal--;
        if(bal < 0) return false;
    }
    return (bal == 0);
}

void solve(){
    int n; cin>>n;
    string x; cin>>x;
    for(int i=1;i<=n;i++) s[i] = x[i - 1];
    int np = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '0') np++;
    }
    if(np & 1){
        cout<<"NO"<<"\n";
        return;
    }

    string a = "";
    string b = "";
    int bal = 0;
    int last = 0;
    int p = (n - np) / 2;
    for(int i=1;i<=n;i++){
        if(s[i] == '1'){
            if(p){
                p--;
                a += "(";
                b += "(";
            }
            else{
                a += ")";
                b += ")";
            }
        }
        else{
            if(last == 0){
                a += "(";
                b += ")";
                last = 1;
            }
            else{
                a += ")";
                b += "(";
                last = 0;
            }
        }
    }
    if(ok(a) && ok(b)){
        cout<<"YES"<<"\n";
        cout<<a<<"\n";
        cout<<b<<"\n";
    }
    else cout<<"NO"<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}