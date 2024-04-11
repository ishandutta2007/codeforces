#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, a=0, b=0, c=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x%3==0) a++;
            if (x%3==1) b++;
            if (x%3==2) c++;
        }
        while (b && c) {
            a++, b--, c--;
        }
        cout << a+b/3+c/3 << "\n";
    }
    return 0;
}