#include <bits/stdc++.h>


using namespace std;

inline bool ok(int n) {
    if(n % 4 == 0) {
        if(n % 100 == 0) {
            if(n % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    bool flag;
    //ios::sync_with_stdio(false);
    cin >> n;
    int aux = n;
    int sum = 0;
    do{
        if(ok(n) == 1)
            sum += 2;
        else
            sum++;
        if(sum >= 7)
            sum -= 7;
        n++;
    }while(sum > 0 || ok(aux) != ok(n));
    cout << n;
    //cin.close();
    //cout.close();
    return 0;
}