#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}


int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    string s;
    int rez = 0;
    for(int j = 0;j<n;j++){
        cin >> s;
        cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '4' || s[i] == '7') cnt++;
        }
        if(cnt <= k) rez++;
    }
    cout << rez;
    return 0;
}