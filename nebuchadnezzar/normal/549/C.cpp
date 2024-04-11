#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n, k;
int odd, even;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num & 1) {
            ++odd;
        } else {
            ++even;
        }
    }

    if (k == 0 || !odd) {
        cout << "Daenerys" << endl;
        return 0;
    }

    if (!even || k == n) {
        if ((odd - (n - k)) & 1) {
            cout << "Stannis" << endl;
            return 0;
        } else {
            cout << "Daenerys" << endl;
            return 0;
        }
    }

    

    if (!((n - k) & 1)) {
        int num = (n - k) / 2;
        
        

        if (even <= num) {
            if ((odd - (n - k - even)) % 2 == 1) {
                cout << "Stannis" << endl;
                return 0;
            }
        }

        if (odd % 2 == 1) {
            cout << "Daenerys" << endl;
            return 0;
        }
        
        /*
        if (odd == num + 1 && even == num + 1) {
            if ((odd - (n - k - even)) % 2 == 0) {
                cout << "Daenerys" << endl;
                return 0;
            }
        }*/

        cout << "Daenerys" << endl;
        return 0;
    }

    if ((n - k) & 1) {
        //cout << "@" << endl;
        int num = (n - k) / 2;
        
        if (even <= num) {
            if ((odd - (n - k - even)) % 2 == 0) {
                cout << "Daenerys" << endl;
                return 0;
            }
        }
        if (odd <= num) {
            cout << "Daenerys" << endl;
            return 0;
        }
        if (odd == num + 1 && even == num + 1) {
            if ((odd - (n - k - even)) % 2 == 0) {
                cout << "Daenerys" << endl;
                return 0;
            }
        }
        cout << "Stannis" << endl;
    }

    return 0;
}