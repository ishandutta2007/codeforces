#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    int gc = sk[0];
    for(int i = 1;i<n;i++){
        gc = __gcd(sk[i],gc);
    }
    bool can = true;
    int dv;
    for(int i = 0;i<n;i++){
        dv = sk[i]/gc;
        while(dv > 1){
            if(dv%2 == 0){
                dv/=2;
            }
            else if(dv%3 == 0){
                dv/=3;
            }
            else{
                can = false;
                break;
            }
        }
    }
    if(can == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}