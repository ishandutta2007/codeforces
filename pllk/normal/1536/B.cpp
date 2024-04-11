#include <iostream>
#include <set>
    
using namespace std;
    
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> z;
        for (int i = 0; i < n; i++) {
            z.insert(s.substr(i,1));
            if (i < n-1) {
                z.insert(s.substr(i,2));
            }
            if (i < n-2) {
                z.insert(s.substr(i,3));
            }
        }
        for (char x = 'a'; x <= 'z'; x++) {
            string u = " ";
            u[0] = x;
            if (!z.count(u)) {
                cout << u << "\n";
                goto end;
            }
        }
        for (char x = 'a'; x <= 'z'; x++) {
            for (char y = 'a'; y <= 'z'; y++) {
                string u = "  ";
                u[0] = x;
                u[1] = y;
                if (!z.count(u)) {
                    cout << u << "\n";
                    goto end;
                }
            }
        }
        for (char x = 'a'; x <= 'z'; x++) {
            for (char y = 'a'; y <= 'z'; y++) {
                for (char h = 'a'; h <= 'z'; h++) {
                    string u = "   ";
                    u[0] = x;
                    u[1] = y;
                    u[2] = h;
                    if (!z.count(u)) {
                        cout << u << "\n";
                        goto end;
                    }
                }
            }
        }
        end: ;
    }
}