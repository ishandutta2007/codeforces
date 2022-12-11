#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    int x1,y1,x2,y2;
    int x,y;
    cin >> x1 >> y1 >> x2 >> y2;
    int distX = abs(x2 - x1);
    int distY = abs(y2 - y1);
    cin >> x >> y;
    if(distX == 0 && distY % y == 0 && (distY / y) % 2 == 0){
        cout << "YES";
    }
    else if(distY == 0 && distX % x == 0 && (distX / x) % 2 == 0){
        cout << "YES";
    }
    else if(distX % x == 0 && distY % y == 0){
        if(distX / x == distY / y){
            cout << "YES";
        }
        else{
            if(abs((distX / x) - (distY / y)) % 2 == 0){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
    }
    else{
        cout <<"NO";
    }
    return 0;
}