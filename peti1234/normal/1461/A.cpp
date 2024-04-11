#include <iostream>

using namespace std;
int w, n, k;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            if (i%3==0) cout << 'a';
            if (i%3==1) cout << 'b';
            if (i%3==2) cout << 'c';
        }
        cout << "\n";
    }
    return 0;
}