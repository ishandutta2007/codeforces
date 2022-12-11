#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    string name[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int j = 1;
    while(n-(j*5) > 0){
        n-=(j*5);
        j*=2;
    }
    int p = 0;
    while(n-j>0){
        n-=j;
        p++;
    }
    cout << name[p];
    return 0;
}