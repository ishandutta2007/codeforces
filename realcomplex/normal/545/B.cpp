#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,p;
    cin >> s >> p;
    int k = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] != p[i]){
            k++;
        }
    }
    if(k%2==1){
        cout << "impossible";
        exit(0);
    }
    int t = 0;
    for(int j = 0;j<s.size();j++){
        if(s[j]!=p[j]){
            if(t == 0){
                cout << 1-(s[j]-48);
            }
            else{
                cout << 1-(p[j]-48);
            }
            t = 1-t;
        }
        else{
            cout << s[j];
        }
    }
    return 0;
}