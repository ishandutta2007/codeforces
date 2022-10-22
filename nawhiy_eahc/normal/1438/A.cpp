#include <iostream>
#define forn(i, n) for(i=1;i<=n;i++)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, i;
        cin >> n;
        forn(i, n) cout << "1 ";
        cout << "\n";
    }
    return 0;
}