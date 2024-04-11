#include <iostream>

using namespace std;

int k,l,m,n,d;

int main() {
    cin>>k>>l>>m>>n>>d;
    int t = 0;
    for (int i = 1; i <= d; i++) {
        if (i%k==0 || i%l==0 || i%m==0 || i%n==0) t++;
    }
    cout << t << endl;
}