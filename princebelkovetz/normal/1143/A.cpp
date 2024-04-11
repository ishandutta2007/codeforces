#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x;
    int ind0 = -1, ind1= -1 ;
    for (int i = 0; i < n; ++i){
        if (a[i] == 0) ind0 = i;
        else ind1 = i;
    }
    cout << min(ind1, ind0) + 1 << '\n';
    
    return 0;
}