#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << ((n%7==6) ? (n/7)*2+1 : (n/7)*2);
    cout <<" " << n/7*2+min(n%7, 2);
    return 0;
}