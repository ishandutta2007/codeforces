#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int q[maxn], sz;

int main(){
    ios::sync_with_stdio(0);
    for (int i = 2; i <= 100; i++){
        bool is = 1;
        for (int j = 2; j < i && is; j++)
            if (i % j == 0)
                is = 0;
        if (is)
            q[sz] = i, sz++;
    }
    int x, ez = 0;
    for (int i = 0; i < 4; i++){
        cout << q[i] << endl;
        string s;
        cin >> s;
        if (s == "yes")
            ez++, x = q[i];
    }
    if (ez > 1){
        cout << "composite" << endl;
        return 0;
    }
    if (ez == 0){
        cout << "prime" << endl;
        return 0;
    }
    cout << x * x << endl;
    string s;
    cin >> s;
    if (s == "yes"){
        cout << "composite" << endl;
        return 0;
    }
    for (int i = 4; i < 15; i++){
        cout << q[i] << endl;
        cin >> s;
        if (s == "yes"){
            cout << "composite" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;
}