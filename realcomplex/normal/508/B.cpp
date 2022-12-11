#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for(int j = 0;j<s.size()-1;j++){
        if(s[j]%2==0 && s[j]<s[s.size()-1]){
            swap(s[j],s[s.size()-1]);
            cout << s;
            exit(0);
        }
    }
    for(int x = s.size()-2;x>=0;x--){
        if(s[x]%2==0){
            swap(s[x],s[s.size()-1]);
            cout << s;
            exit(0);
        }
    }
    cout << -1;
    exit(0);
    return 0;
}