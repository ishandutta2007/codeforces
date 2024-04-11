#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;



int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    int e = 20000;
    int x = e;
    cin >> n;
    for (int i = 0; i < n; i++){
        int s;
        string t;
        cin >> s >> t;
        if (t == "South"){
            if (x < s){
                cout << "NO";
                return 0;
            }
            x -= s;
        }
        else
        if (t == "North"){
            if (e - x < s){
                cout << "NO";
                return 0;
            }
            x += s;
        }
        else
        if (x == e || x == 0){
            cout << "NO";
            return 0;
        }
    }
    if (x == e)
        cout << "YES";
    else
        cout << "NO";
}