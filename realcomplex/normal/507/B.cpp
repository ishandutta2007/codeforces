#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double PI = 4*atan(1);

#define DECIMAL fixed << setprecision(7)

int main()
{
    double r,x,y,x1,y1;
    cin >> r >> x >> y >> x1 >> y1;
    double len = abs(x-x1)*abs(x-x1);
    len += abs(y-y1)*abs(y-y1);
    len = sqrt(len);
    if(x==x1&&y==y1){
        cout << 0;
    }
    else{
        r*=2;
        int op = 0;
        while(len>0){
            len-=r;
            op++;
        }
        cout << op;
    }
    return 0;
}