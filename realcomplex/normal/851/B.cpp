#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double dis(double x,double x1,double y,double y1){
    return ((x-x1) * (x-x1))+((y-y1) * (y-y1));
}

int main() {

    double ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if(dis(ax,bx,ay,by) != dis(bx,cx,by,cy) || ((ax+cx)/2==bx && (ay+cy)/2==by)){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
	return 0;
}