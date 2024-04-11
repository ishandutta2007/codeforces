#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    char a,b,c,d;
    cin >> a >> b >> c >> d;
    int x,x1,y,y1;
    x = a - 96;
    x1 = c - 96;
    y = b - 48;
    y1 = d - 48;
    y = 9 - y;
    y1 = 9 - y1;
    cout << max(abs(x1 - x),abs(y1 - y))<< "\n";
    while(x != x1 || y != y1){
        if(x1 > x && y1 > y){
            cout << "RD" << "\n";
            x++;
            y++;
        }
        else if(x1 < x && y1 > y){
            cout << "LD" << "\n";
            x--;
            y++;
        }
        else if(x1 < x && y1 < y){
            cout << "LU" << "\n";
            x--;
            y--;
        }
        else if(x1 > x && y1 < y){
            cout << "RU" << "\n";
            x++;
            y--;
        }
        else if(x1 > x){
            cout << "R" << "\n";
            x++;
        }
        else if(x > x1){
            cout << "L" << "\n";
            x--;
        }
        else if(y > y1){
            y--;
            cout << "U" << "\n";
        }
        else if(y < y1){
            y++;
            cout << "D" << "\n";
        }
    }
    return 0;
}