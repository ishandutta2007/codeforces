                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[200];
int mn, mx;
string str;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    for(int i = 3; i < 400; i++)
        if((i - 2) * 180 % i == 0)
            st.insert((i - 2) * 180 / i);
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(st.find(a) != st.end())
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}