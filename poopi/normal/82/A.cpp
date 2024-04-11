                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
string str[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(){
    cin >> n;
    n--;
    int cnt = 1;
    while(n >= cnt * 5){
        n -= cnt * 5;
        cnt *= 2;
    }
    cout << str[n / cnt] << endl;
    return 0;
}