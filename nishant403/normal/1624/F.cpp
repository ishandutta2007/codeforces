#include <bits/stdc++.h>
using namespace std;
  
int ask(int x) {
    cout << "+ " << x << endl;
    cin >> x;
    return x;
}

void answer(int x) {
    cout <<"! " << x << endl;
    exit(0);
}

signed main()
{
    int n;
    cin >> n;

    int L = 1;
    int R = n-1;

    int cur = 0;

    //It is always true that , L % n <= R % n 
    while(L < R) {
        int mid = (L + R)/2;

        //add maximum value such that cur doesn't change, then we say x is in r1, otherwise x is in r2
        int val = (n - 1 - (mid % n));

        int tmp = ask(val);

        if(tmp == cur) {
            R = mid;
        } else {
            L = mid + 1;
        }

        L += val;
        R += val;
        cur = tmp;
    }

    answer(L);
}