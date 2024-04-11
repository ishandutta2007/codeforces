#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, a, ma;
    cin >> q;

    set<int> pow;
    for(int i = 0; i<30; i++){
        pow.insert((1 << i));
    }

    for(int i = 0; i<q; i++){
        cin >> a;
        if(pow.count(a + 1)){
            ma = 1;
            for(int j = 2; j*j<=a; j++){
                if(a % j == 0){
                    ma = max(ma, a / j);
                }
            }

            cout << ma << endl;
        }

        else cout << *pow.upper_bound(a) - 1 << endl;
    }

}