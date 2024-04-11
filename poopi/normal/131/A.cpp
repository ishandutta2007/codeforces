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

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str;
    cin >> str;
    bool f = false;
    for(int i = 1; i < str.length(); i++)
        if(islower(str[i]))
            f = true;
    if(!f){
        for(int i = 0; i < str.length(); i++){
            if(islower(str[i]))
                str[i] = toupper(str[i]);
            else str[i] = tolower(str[i]);
        }
    }
    cout << str << endl;
    return 0;
}