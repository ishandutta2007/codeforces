#include <bits/stdc++.h>
using namespace std;

int main(){
   int n, x;
   int k = 13;
   cin >> n;

   int x1, x2, y1, y2;
   x2 = n + 1;
   y2 = n + 1;
   x1 = -1;
   y1 = -1;

   for(int i = 1; i<=n; i++){
        cout << "? " << 1 << " " << 1 << " " << i << " " << n << endl;
        fflush(stdout);
        cin >> x;
        if(x % 2 && x1 == -1) x1 = i;
        if(x % 2 == 0 && x2 == n + 1 && x1 != -1) x2 = i;
   }

   for(int i = 1; i<=n; i++){
        cout << "? " << 1 << " " << 1 << " " << n << " " << i << endl;
        fflush(stdout);
        cin >> x;
        if(x % 2 && y1 == -1) y1 = i;
        if(x % 2 == 0 && y2 == n + 1 && y1 != - 1) y2 = i;
   }

   if(x1 != -1){
        if(y1 != -1){
            cout << "? " << x1 << " " << y1 << " " << x1 << " " << y1 << endl;
            fflush(stdout);
            cin >> x;
            if(x % 2){
                cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                return 0;
            }

            else{
                cout << "! " << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
                return 0;
            }
        }

        int d, h, mid;
        d = 1;
        h = n;
        for(int i = 0; i<k; i++){
            mid = (d + h)/2;
            cout << "? " << x1 << " " << d << " " << x1 << " " << mid << endl;
            cin >> x;
            if(x % 2) h = mid;
            else d = mid + 1;
        }

        cout << "! " << x1 << " " << mid << " " << x2 << " " << mid << endl;
        return 0;
   }


    int d, h, mid;
    d = 1;
    h = n;
    for(int i = 0; i<k; i++){
        mid = (d + h)/2;
        cout << "? " << d << " " << y1 << " " << mid << " " << y1 << endl;
        cin >> x;
        if(x % 2) h = mid;
        else d = mid + 1;
    }

    cout << "! " << mid << " " << y1 << " " << mid << " " << y2 << endl;
    return 0;
}