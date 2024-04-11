#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    int v[100];
int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        for (int j = 0; j < a; j++){
            int x;
            cin >> x;
            v[x - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    if (v[i] == 0){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}