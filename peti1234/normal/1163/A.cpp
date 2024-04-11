#include <iostream>

using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    if (k==0) {
        k++;
    }
    cout << min(k, n-k) << endl;
    return 0;
}