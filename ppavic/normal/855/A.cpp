#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

map < string, bool > bio;

int n;
string s;

int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> s;
        if(bio[s]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        bio[s] = 1;
    }
}