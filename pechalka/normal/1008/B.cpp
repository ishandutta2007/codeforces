#include <iostream>
#include <string>

using namespace std;

int main(){
    long long n;
    cin >> n;
    bool ans = true;
    long long prev = 1e9 + 100;
    for (int i = 0 ; i < n; ++i){
        long long a, b;
        cin >> a >> b;
        if (a <= prev && b <= prev)
            prev = max(a, b);
        else if (a <= prev)
            prev = a;
        else if (b <= prev)
            prev = b;
        else
            ans = false;
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}