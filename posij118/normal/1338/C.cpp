#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        long long pos = (n - 1) / 3;
        long long a;

        for(int i = 0; i<60; i+=2){
            if(pos >= (1LL << i)) pos -= (1LL << i);
            else{
                a = (1LL << i) + pos;
                break;
            }
        }

        long long b, c;
        b = 0;
        c = 0;

        for(int i = 0; i<60; i+=2){
            //cout << b << endl;
            bool x = (1LL << i) & a;
            bool y = (1LL << (i + 1)) & a;

            if(x & y){
                b += (1LL << i);
                c += (1LL << (i + 1));
            }

            if(x & !y){
                b += (1LL << (i + 1));
                c += (1LL << (i + 1)) + (1LL << i);
            }

            if(!x & y){
                c += (1LL << i);
                b += (1LL << (i + 1)) + (1LL << i);
            }
        }

        if((n - 1) % 3 == 0) cout << a << endl;
        else if((n - 1) % 3 == 1) cout << b << endl;
        else cout << c << endl;
    }
}