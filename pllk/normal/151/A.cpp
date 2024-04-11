#include <iostream>

using namespace std;

int n,k,l,c,d,p,nl,np;
int x,y,z;
int t;

int main() {
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    x = k*l;
    y = c*d;
    z = p;
    while (x >= nl*n && y >= n && z >= np*n) {
        t++;
        x -= nl*n;
        y -= n;
        z -= np*n;
    }
    cout << t << endl;
}