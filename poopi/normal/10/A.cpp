                        /* in the name of Allah */
#include<iostream>
#include<string>
using namespace std;

int n, t1, t2;
int p1, p2, p3;

int main(){
    int a, b, c, sum = 0;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    cin >> a >> b;
    sum += (b - a) * p1;
    for(int i = 1; i < n; i++){
        c = b;
        cin >> a >> b;
        sum += (b - a) * p1;
        int dif = a - c;
        int tmp = min(dif, t1);
        sum += tmp * p1;
        dif -= tmp;
        tmp = min(dif, t2);
        sum += tmp * p2;
        dif -= tmp;
        sum += dif * p3;
    }
    cout << sum << endl;
    return 0;
}