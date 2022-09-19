#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        string a, b;
        cin >> a >> b;
        char ut='.';
        while (a.size()>0) {
            while (b.size()>0 && a.back()!=b.back() && b.back()==ut) b.pop_back();
            if (b.size()>0 && a.back()==b.back()) {
                ut=b.back();
                a.pop_back(), b.pop_back();
            } else {
                break;
            }
        }
        while (b.size()>0 && b.back()==ut) {
            b.pop_back();
        }
        cout << (a.size()==0 && b.size()==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}