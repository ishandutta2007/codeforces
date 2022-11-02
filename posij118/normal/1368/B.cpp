#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    cin >> k;

    int a[10];
    string s = "codeforces";

    fill(a, a + 10, 1);
    long long mult = 1;

    while(mult < k){
        bool flag = 0;

        for(int i = 1; i<10; i++){
            if(a[i] < a[i - 1]){
                mult /= a[i];
                mult *= a[i - 1];
                a[i]++;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            mult /= a[0];
            mult *= a[0] + 1;
            a[0]++;
        }
    }

    for(int i = 0; i<10; i++){
        for(int j = 0; j<a[i]; j++){
            cout << s[i];
        }
    }

}