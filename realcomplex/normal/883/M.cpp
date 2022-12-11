#include <bits/stdc++.h>

using namespace std;

int main(){
        int x,y,x1,y1;
        cin >> x >> y >> x1 >> y1;
        cout << (max(abs(x-x1),1)+2+max(abs(y1-y),1))*2;
        return 0;
}