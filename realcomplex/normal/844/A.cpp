#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int cnt[26];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    if(k>n){
        cout << "impossible";
        return 0;
    }
    for(int j = 0;j<n;j++){
        cnt[s[j]-97]++;
    }
    int am = 0;
    for(int x = 0;x<26;x++){
        if(cnt[x] > 0){
            am++;
        }
    }
    if(am>k){
        cout << 0;
        return 0;
    }
    cout << k-am;
    return 0;
}