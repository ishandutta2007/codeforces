#include <bits/stdc++.h>
#include <random>
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


void solve(){
    int mini = 10;
    string s; cin >> s;
    for(int i=0;i<1024;i++){
        string cur = "";
        for(int j=0;j<10;j++){
            if(i & (1 << j)){
                cur += "1";
            }
            else cur += "0";
        }
        bool ok = true;
        for(int j=0;j<10;j++){
            if(cur[j] != s[j] && s[j] != '?') ok = false;
        }
        if(ok){
            int a = 0;
            int b = 0;
            for(int j=0;j<10;j++){
                if(cur[j] == '1'){
                    if(j & 1) b++;
                    else a++;
                }
                int a_can = (9 - j) / 2;
                int b_can = (10 - j) / 2;
                if(a > b){
                    if(b + b_can < a){
                        mini = min(mini, j + 1);
                    }
                }
                if(b > a){
                    if(a + a_can < b){
                        mini = min(mini, j + 1);
                    }
                }
            }
        }
    }
    cout << mini << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}