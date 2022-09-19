#include <iostream>

using namespace std;
int w, a, b, c, d;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        cout << max(c-1, a-c)+max(d-1, b-d) << "\n";
    }
    return 0;
}