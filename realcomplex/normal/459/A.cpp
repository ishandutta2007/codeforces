#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(abs(x2-x1) != abs(y1-y2) && (abs(x2-x1) != 0 && abs(y2-y1) != 0)){
        cout << -1;
    }
    else{
        if(x1 == x2){
            cout << x1 + abs(y2-y1) << " " << y1 << " " << x1 + abs(y2-y1) << " " << y2;
        }
        else if(y1 == y2){
            cout << x1 << " " << y1+abs(x1-x2) << " " << x2 << " " << y2+abs(x1-x2);
        }
        else{
            cout << x1 << " " << y2 << " " << x2 << " " << y1;
        }
    }
    return 0;
}