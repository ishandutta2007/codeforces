#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    int rez;
    bool sn = true;
    while(sn == true){
        sn = false;
        for(int i = 1;i<n;i++){
            if(sk[i] < sk[i - 1]){
                rez = sk[i];
                sk[i] = sk[i - 1];
                sk[i - 1] = rez;
                cout << i << " " << i + 1 << "\n";
                sn = true;
            }
        }
    }
    return 0;
}