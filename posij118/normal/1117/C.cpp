#include <bits/stdc++.h>
using namespace std;

int main(){
    long long d, h, mid;
    h = 1e12;
    d = 0;
    string s;

    int n;
    int x1, x2, y1, y2;
    long long diffx, diffy;
    diffx = 0;
    diffy = 0;
    long long xn, yn;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n;
    cin >> s;

    for(int i = 0; i<n; i++){
        if(s[i] == 'D') diffy--;
        if(s[i] == 'U') diffy++;
        if(s[i] == 'L') diffx--;
        if(s[i] == 'R') diffx++;
    }

    for(int i = 0; i<42; i++){
        mid = (d + h) / 2;
        xn = x1 + diffx * mid;
        yn = y1 + diffy * mid;
        if(abs(xn - x2) + abs(yn - y2) <= mid * n){
            h = mid;
        }

        else d = mid;
    }
      xn = x1 + diffx * d;
    yn = y1 + diffy * d;
    for(int i = 0; i<n; i++){


        if(s[i] == 'D') yn--;
        if(s[i] == 'U'){
                yn++;

        }
        if(s[i] == 'L') xn--;
        if(s[i] == 'R') xn++;

        if(abs(xn - x2) + abs(yn - y2) <= d * n + i + 1){
            cout << d * n + i + 1;
            return 0;
        }

        if (i == n - 1) cout << -1;
    }
}