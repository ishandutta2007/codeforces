#include <iostream>
 
using namespace std;
 
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a<=(min(b, c))) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}