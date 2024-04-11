                    /* in the name of Allah */
#include <iostream>
using namespace std;

int main(){
    int n, v;
    double a[30];
    double b[30];
    cin >> n >> v;
    double s = 0;
    for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
    }
    double mx = 200;
    for(int i = 0; i < n; i++){
            cin >> b[i];
            mx = min(mx, b[i] / a[i]);
    }
    printf("%.5lf\n", min((double)v, s * mx));
//    cin >> v;
    return 0;
}