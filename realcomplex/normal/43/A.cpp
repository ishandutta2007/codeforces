#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    map<string,int>rez;
    string s;
    string win;
    int score = 0;
    for(int j =0;j<n;j++){
        cin >> s;
        rez[s]++;
        if(rez[s]>score){
            score = rez[s];
            win = s;
        }
    }
    cout << win;
    return 0;
}