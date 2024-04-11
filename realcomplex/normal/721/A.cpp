#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    char s;
    vector<int>cod;
    int cnt = 0;
    for(int j = 0;j<n;j++){
        cin >> s;
        if(s=='B'){
            cnt++;
        }
        if(j == n-1 || s == 'W'){
            if(cnt != 0){
                cod.push_back(cnt);
            }
            cnt = 0;
        }
    }
    cout << cod.size() << "\n";
    for(int j = 0;j<cod.size();j++){
        cout << cod[j] << " ";
    }
    return 0;
}