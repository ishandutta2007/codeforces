                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <fstream>
using namespace std;


#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a, b, d = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(d + b <= 500){
            cout << "G";
            d += b;
        }
        else{
            cout << "A";
            d -= a;
        }
    }
    cout << endl;
    return 0;
}