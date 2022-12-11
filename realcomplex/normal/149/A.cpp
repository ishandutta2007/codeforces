#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int k;
    cin >> k;
    if(k == 0){
        cout << 0;
    }
    else{
        int s[12];
        for(int i = 0;i<12;i++){
            cin >> s[i];
        }
        sort(s,s+12);
        int m = 0;
        int sum = 0;
        for(int i = 11;i>=0;i--){
            sum += s[i];
            m++;
            if(sum >= k){
                break;
            }
        }
        if(sum < k){
            cout << -1;
        }
        else{
            cout << m;
        }
    }
    return 0;
}